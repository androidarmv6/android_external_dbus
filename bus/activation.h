/* -*- mode: C; c-file-style: "gnu" -*- */
/* activation.h  Activation of services
 *
 * Copyright (C) 2003  CodeFactory AB
 *
 * Licensed under the Academic Free License version 1.2
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef BUS_ACTIVATION_H
#define BUS_ACTIVATION_H

#include <dbus/dbus.h>
#include <dbus/dbus-list.h>
#include "bus.h"

BusActivation* bus_activation_new              (BusContext        *context,
                                                const DBusString  *address,
                                                DBusList         **directories,
                                                DBusError         *error);
void           bus_activation_ref              (BusActivation     *activation);
void           bus_activation_unref            (BusActivation     *activation);
dbus_bool_t    bus_activation_activate_service (BusActivation     *activation,
                                                DBusConnection    *connection,
                                                DBusMessage       *activation_message,
                                                const char        *service_name,
                                                DBusError         *error);
dbus_bool_t    bus_activation_service_created  (BusActivation     *activation,
                                                const char        *service_name,
                                                DBusError         *error);


#endif /* BUS_ACTIVATION_H */
