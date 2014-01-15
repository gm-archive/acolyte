// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "art/object.hpp"
#include "art/vector.hpp"

#include <memory>
#include <iostream>

namespace art {
  namespace intern {
    const object::id_t first_object_id = 1000001;
    
    decltype(event_schedule) event_schedule;
    decltype(events_pending_removal) events_pending_removal;
    decltype(object_map) object_map;
    
    events_by_depth_t::iterator event_link(real_t depth, event& ev) {
      return event_schedule[ev.type].insert(std::make_pair(depth, ev));
    }
    
    void event_unlink(events_by_depth_t::iterator& it) {
      event_schedule[(*it).second.type].erase(it);
    }
    
    object& object_from_id(object::id_t id) {
      auto it = object_map.find(id);
      if (it == object_map.end()) {
        std::cerr << "error: object does not exist" << std::endl;
        std::abort();
      }
      return *it->second;
    }
    
    void with(real_t num, with_fn_t fn) {
      switch(static_cast<unsigned long>(num)) {
        case all:
          return with_objects_all(fn);
        case noone:
          return;
        default:
          return (num < first_object_id) ?
            with_objects_index(static_cast<object::index_t>(num), fn) : with_objects_id(static_cast<object::id_t>(num), fn);
      }
    }
    
    void with_objects_all(with_fn_t fn) {
      for (auto& obj : object_map) {
        fn(*obj.second);
      }
    }
    
    void with_objects_id(object::id_t id, with_fn_t fn) {
      fn(object_from_id(id));
    }
    
    void with_objects_index(object::index_t index, with_fn_t fn) {
      for (auto& obj : object_map) {
        if (obj.second->object_index() == index) {
          fn(*obj.second);
        }
      }
    }
  }
  
  object::object(index_t index, id_t id, real_t xpos, real_t ypos, bool solid, bool visible, bool persistent, real_t depth,
                 real_t sprite_index, real_t mask_index, std::vector<event>& events)
      // Specific
    : defined_events(events), linked_events(defined_events.size()), _index(index), _id(id), _xstart(xpos), _ystart(ypos), _x(xpos), _y(ypos), _solid(solid), _visible(visible), _persistent(persistent),
      _depth(depth), _sprite_index(sprite_index), _mask_index(mask_index),
                 
      // Defaults
      _xprevious(_x), _yprevious(_y), _image_alpha(1), _image_angle(0), _image_blend(0), _image_index(0), _image_speed(1),
      _image_xscale(1), _image_yscale(1), _direction(0), _friction(0), _hfriction(0), _vfriction(0), _gravity(0), _hgravity(0), _vgravity(0),
      _gravity_direction(0), _speed(0), _hspeed(0), _vspeed(0) {
        
    this->object::unsafe_link_events();
  }
  
  object::~object() {
    this->unsafe_unlink_events();
  }
  
  void object::unsafe_link_events() {
    size_t n = 0;
    for (auto& ev : this->defined_events) {
      this->linked_events[n++] = intern::event_link(this->_depth, ev);
    }
  }
  
  void object::link_events() {
    this->unsafe_unlink_events();
    this->linked_events.resize(this->defined_events.size());
    this->unsafe_link_events();
  }
  
  void object::unsafe_unlink_events() {
    for (auto& ev : this->linked_events) {
      intern::events_pending_removal.push_front(ev);
      (*ev).second.status = event::st_removed;
    }
  }
  
  void object::unlink_events() {
    this->unsafe_unlink_events();
    this->linked_events.clear();
  }
  
  property_ro<object, object::id_t, &object::get_object_index> object::object_index() {
    return {this};
  }
  
  bool object::get_solid() {
    return this->_solid;
  }
  
  void object::set_solid(bool solid) {
    this->_solid = solid;
  }
  
  property<object, bool, &object::get_solid, &object::set_solid> object::solid() {
    return {this};
  }
  
  bool object::get_visible() {
    return this->_visible;
  }
  
  void object::set_visible(bool visible) {
    // TODO: link/unlink draw event from event chain
    this->_visible = visible;
  }
  
  property<object, bool, &object::get_visible, &object::set_visible> object::visible() {
    return {this};
  }
  
  bool object::get_persistent() {
    return this->_persistent;
  }
  
  void object::set_persistent(bool persistent) {
    this->_persistent = persistent;
  }
  
  property<object, bool, &object::get_persistent, &object::set_persistent> object::persistent() {
    return {this};
  }
  
  real_t object::get_depth() {
    return this->_depth;
  }
  
  void object::set_depth(real_t depth) {
    this->_depth = depth;
    this->unsafe_unlink_events();
    this->unsafe_link_events();
  }
  
  property<object, real_t, &object::get_depth, &object::set_depth> object::depth() {
    return {this};
  }
  
  real_t object::get_sprite_index() {
    return this->_sprite_index;
  }
  
  void object::set_sprite_index(real_t sprite) {
    this->_sprite_index = sprite;
  }
  
  property<object, real_t, &object::get_sprite_index, &object::set_sprite_index> object::sprite_index() {
    return {this};
  }
  
  real_t object::get_sprite_width() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_sprite_width> object::sprite_width() {
    return {this};
  }
  
  real_t object::get_sprite_height() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_sprite_height> object::sprite_height() {
    return {this};
  }
  
  real_t object::get_sprite_xoffset() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_sprite_xoffset> object::sprite_xoffset() {
    return {this};
  }
  
  real_t object::get_sprite_yoffset() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_sprite_yoffset> object::sprite_yoffset() {
    return {this};
  }
  
  real_t object::get_image_alpha() {
    return this->_image_alpha;
  }
  
  void object::set_image_alpha(real_t alpha) {
    this->_image_alpha = alpha;
  }
  
  property<object, real_t, &object::get_image_alpha, &object::set_image_alpha> object::image_alpha() {
    return {this};
  }
  
  real_t object::get_image_angle() {
    return this->_image_angle;
  }
  
  void object::set_image_angle(real_t angle) {
    this->_image_angle = angle;
  }
  
  property<object, real_t, &object::get_image_angle, &object::set_image_angle> object::image_angle() {
    return {this};
  }
  
  real_t object::get_image_blend() {
    return this->_image_blend;
  }
  
  void object::set_image_blend(real_t blend) {
    this->_image_blend = blend;
  }
  
  property<object, real_t, &object::get_image_blend, &object::set_image_blend> object::image_blend() {
    return {this};
  }
  
  real_t object::get_image_index() {
    return this->_image_index;
  }
  
  void object::set_image_index(real_t index) {
    this->_image_index = index;
  }
  
  property<object, real_t, &object::get_image_index, &object::set_image_index> object::image_index() {
    return {this};
  }
  
  real_t object::get_image_number() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_image_number> object::image_number() {
    return {this};
  }
  
  real_t object::get_image_speed() {
    return this->_image_speed;
  }
  
  void object::set_image_speed(real_t speed) {
    this->_image_speed = speed;
  }
  
  property<object, real_t, &object::get_image_speed, &object::set_image_speed> object::image_speed() {
    return {this};
  }
  
  real_t object::get_image_xscale() {
    return this->_image_xscale;
  }
  
  void object::set_image_xscale(real_t xscale) {
    this->_image_xscale = xscale;
  }
  
  property<object, real_t, &object::get_image_xscale, &object::set_image_xscale> object::image_xscale() {
    return {this};
  }
  
  real_t object::get_image_yscale() {
    return this->_image_yscale;
  }
  
  void object::set_image_yscale(real_t yscale) {
    this->_image_yscale = yscale;
  }
  
  property<object, real_t, &object::get_image_yscale, &object::set_image_yscale> object::image_yscale() {
    return {this};
  }
  
  real_t object::get_mask_index() {
    return this->_mask_index;
  }
  
  void object::set_mask_index(real_t index) {
    this->_mask_index = index;
  }
  
  property<object, real_t, &object::get_mask_index, &object::set_mask_index> object::mask_index() {
    return {this};
  }
  
  real_t object::get_bbox_bottom() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_bbox_bottom> object::bbox_bottom() {
    return {this};
  }
  
  real_t object::get_bbox_left() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_bbox_left> object::bbox_left() {
    return {this};
  }
  
  real_t object::get_bbox_right() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_bbox_right> object::bbox_right() {
    return {this};
  }
  
  real_t object::get_bbox_top() {
    // TODO
    return 0;
  }
  
  property_ro<object, real_t, &object::get_bbox_top> object::bbox_top() {
    return {this};
  }
  
  real_t object::get_direction() {
    return this->_direction;
  }
  
  void object::set_direction(real_t direction) {
    this->_direction = direction;
    this->update_hspeed();
    this->update_vspeed();
    this->update_friction();
  }
  
  void object::update_direction() {
    this->_direction = intern::vector_direction_rad(this->_hspeed, this->_vspeed);
  }
  
  property<object, real_t, &object::get_direction, &object::set_direction> object::direction() {
    return {this};
  }
  
  real_t object::get_friction() {
    return this->_friction;
  }
  
  void object::set_friction(real_t friction) {
    this->_friction = friction;
    this->update_friction();
  }
  
  void object::update_friction() {
    this->_hfriction = this->_friction * std::cos(this->_direction);
    this->_vfriction = -this->_friction * std::sin(this->_direction);
  }
  
  property<object, real_t, &object::get_friction, &object::set_friction> object::friction() {
    return {this};
  }
  
  real_t object::get_gravity() {
    return this->_gravity;
  }
  
  void object::set_gravity(real_t gravity) {
    this->_gravity = gravity;
    this->update_gravity();
  }
  
  void object::update_gravity() {
    this->_hgravity = this->_gravity * std::cos(this->_gravity_direction);
    this->_vgravity = -this->_gravity * std::sin(this->_gravity_direction);
  }
  
  property<object, real_t, &object::get_gravity, &object::set_gravity> object::gravity() {
    return {this};
  }
  
  real_t object::get_gravity_direction() {
    return radtodeg(this->_gravity_direction);
  }
  
  void object::set_gravity_direction(real_t direction) {
    this->_gravity_direction = degtorad(direction);
    this->update_gravity();
  }
  
  property<object, real_t, &object::get_gravity_direction, &object::set_gravity_direction> object::gravity_direction() {
    return {this};
  }
  
  real_t object::get_hspeed() {
    return this->_hspeed;
  }
  
  void object::set_hspeed(real_t hspeed) {
    this->_hspeed = hspeed;
    this->update_speed();
    this->update_direction();
  }
  
  void object::update_hspeed() {
    this->_hspeed = this->_speed * std::cos(this->_direction);
  }
  
  property<object, real_t, &object::get_hspeed, &object::set_hspeed> object::hspeed() {
    return {this};
  }
  
  real_t object::get_vspeed() {
    return this->_vspeed;
  }
  
  void object::set_vspeed(real_t vspeed) {
    this->_vspeed = vspeed;
    this->update_speed();
    this->update_direction();
  }
  
  void object::update_vspeed() {
    this->_vspeed = -this->_speed * std::sin(this->_direction);
  }
  
  property<object, real_t, &object::get_vspeed, &object::set_vspeed> object::vspeed() {
    return {this};
  }
  
  real_t object::get_speed() {
    return this->_speed;
  }
  
  void object::set_speed(real_t speed) {
    this->_speed = speed;
    this->update_hspeed();
    this->update_vspeed();
  }
  
  void object::update_speed() {
    this->_speed = intern::vector_length(this->_hspeed, this->_vspeed);
  }
  
  property<object, real_t, &object::get_speed, &object::set_speed> object::speed() {
    return {this};
  }
  
  bool instance_exists(object::id_t id) {
    if (id < intern::first_object_id) {
      // TODO
      return false;
    }
    return intern::object_map.find(id) != intern::object_map.end();
  }
}
