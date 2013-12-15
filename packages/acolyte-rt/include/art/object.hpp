// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_OBJECT_HPP_
#define ART_OBJECT_HPP_

#include "art/real.hpp"
#include "art/property.hpp"

#include <memory>
#include <vector>
#include <map>

namespace art {
  struct event;
  
#define def_property(__type, __name) \
  __type get_##__name (); \
  void set_##__name (__type); \
  property<object, __type, &object::get_##__name, &object::set_##__name> __name ()

#define def_property_ro(__type, __name) \
  __type get_##__name (); \
  property_ro<object, __type, &object::get_##__name> __name ()
  
  struct object {
    typedef unsigned long index_t;
    typedef unsigned long id_t;
    
    object(index_t, id_t, real_t, real_t, bool, bool, bool, real_t, real_t, real_t, std::vector<event>&);
    virtual ~object();
    
    virtual void event_create() = 0;
    virtual void event_destroy() = 0;
    
    std::vector<event> defined_events;
    std::vector<std::multimap<real_t, event>::iterator> linked_events;
    
    void unsafe_link_events();
    void link_events();
    void unsafe_unlink_events();
    void unlink_events();
    
    const index_t _index;
    def_property_ro(index_t, object_index);
    
    const id_t _id;
    def_property_ro(id_t, id);
    
    const real_t _xstart;
    def_property_ro(real_t, xstart);
    
    const real_t _ystart;
    def_property_ro(real_t, ystart);
    
    real_t _x;
    def_property(real_t, x);
    
    real_t _y;
    def_property(real_t, y);
    
    bool _solid;
    def_property(bool, solid);
    
    bool _visible;
    def_property(bool, visible);
    
    bool _persistent;
    def_property(bool, persistent);
    
    real_t _depth;
    def_property(real_t, depth);
    
    real_t _sprite_index;
    def_property(real_t, sprite_index);
    
    real_t _mask_index;
    def_property(real_t, mask_index);
    
    real_t _xprevious;
    def_property_ro(real_t, xprevious);
    
    real_t _yprevious;
    def_property_ro(real_t, yprevious);
    
    real_t _image_alpha;
    def_property(real_t, image_alpha);
    
    real_t _image_angle;
    def_property(real_t, image_angle);
    
    real_t _image_blend;
    def_property(real_t, image_blend);
    
    real_t _image_index;
    def_property(real_t, image_index);
    
    real_t _image_speed;
    def_property(real_t, image_speed);
    
    real_t _image_xscale;
    def_property(real_t, image_xscale);
    
    real_t _image_yscale;
    def_property(real_t, image_yscale);
    
    real_t _direction;
    def_property(real_t, direction);
    void update_direction();
    
    real_t _friction;
    real_t _hfriction;
    real_t _vfriction;
    def_property(real_t, friction);
    void update_friction();
    
    real_t _gravity;
    real_t _hgravity;
    real_t _vgravity;
    def_property(real_t, gravity);
    void update_gravity();
    
    real_t _gravity_direction;
    def_property(real_t, gravity_direction);
    
    real_t _speed;
    def_property(real_t, speed);
    void update_speed();
    
    real_t _hspeed;
    def_property(real_t, hspeed);
    void update_hspeed();
    
    real_t _vspeed;
    def_property(real_t, vspeed);
    void update_vspeed();
    
    def_property_ro(real_t, sprite_width);
    def_property_ro(real_t, sprite_height);
    def_property_ro(real_t, sprite_xoffset);
    def_property_ro(real_t, sprite_yoffset);
    def_property_ro(real_t, image_number);
    def_property_ro(real_t, bbox_bottom);
    def_property_ro(real_t, bbox_left);
    def_property_ro(real_t, bbox_right);
    def_property_ro(real_t, bbox_top);
  };
  
#undef def_property
#undef def_property_ro
  
  enum event_type_t {
    ev_create,
    ev_destroy,
    ev_step,
    ev_alarm,
    ev_keyboard,
    ev_mouse,
    ev_collision,
    ev_other,
    ev_draw,
    ev_keyrelease
  };
  
  struct event {
    typedef object::index_t metadata_t;
    std::function<void(const metadata_t)> fn;
    event_type_t type;
    metadata_t metadata;
  };
  
  enum {
    all = 0,
    noone
  };
  
  namespace internal {
    typedef std::multimap<real_t, event> events_by_depth_t;
    extern std::map<event_type_t, events_by_depth_t> event_schedule;
    extern std::map<object::id_t, std::unique_ptr<object>> object_map;
    
    events_by_depth_t::iterator event_link(real_t, event&);
    void event_unlink(events_by_depth_t::iterator&);
    
    object& object_from_id(object::id_t);
    
    typedef std::function<void(object&)> with_fn_t;
    void with(real_t, with_fn_t);
    void with_objects_all(with_fn_t);
    void with_objects_id(object::id_t, with_fn_t);
    void with_objects_index(object::index_t, with_fn_t);
  }
}

#endif // ART_OBJECT_HPP_
