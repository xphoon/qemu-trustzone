/*
 * QEMU MicroBlaze CPU
 *
 * Copyright (c) 2012 SUSE LINUX Products GmbH
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see
 * <http://www.gnu.org/licenses/lgpl-2.1.html>
 */
#ifndef QEMU_MICROBLAZE_CPU_QOM_H
#define QEMU_MICROBLAZE_CPU_QOM_H

#include "qemu/cpu.h"

#define TYPE_MICROBLAZE_CPU "microblaze-cpu"

#define MICROBLAZE_CPU_CLASS(klass) \
    OBJECT_CLASS_CHECK(MicroBlazeCPUClass, (klass), TYPE_MICROBLAZE_CPU)
#define MICROBLAZE_CPU(obj) \
    OBJECT_CHECK(MicroBlazeCPU, (obj), TYPE_MICROBLAZE_CPU)
#define MICROBLAZE_CPU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(MicroBlazeCPUClass, (obj), TYPE_MICROBLAZE_CPU)

/**
 * MicroBlazeCPUClass:
 * @parent_reset: The parent class' reset handler.
 *
 * A MicroBlaze CPU model.
 */
typedef struct MicroBlazeCPUClass {
    /*< private >*/
    CPUClass parent_class;
    /*< public >*/

    void (*parent_reset)(CPUState *cpu);
} MicroBlazeCPUClass;

/**
 * MicroBlazeCPU:
 * @env: #CPUMBState
 *
 * A MicroBlaze CPU.
 */
typedef struct MicroBlazeCPU {
    /*< private >*/
    CPUState parent_obj;
    /*< public >*/

    CPUMBState env;
} MicroBlazeCPU;

static inline MicroBlazeCPU *mb_env_get_cpu(CPUMBState *env)
{
    return MICROBLAZE_CPU(container_of(env, MicroBlazeCPU, env));
}

#define ENV_GET_CPU(e) CPU(mb_env_get_cpu(e))


#endif
