/*
<:copyright-BRCM:2013:DUAL/GPL:standard 

   Copyright (c) 2013 Broadcom Corporation
   All Rights Reserved

Unless you and Broadcom execute a separate written software license
agreement governing use of this software, this software is licensed
to you under the terms of the GNU General Public License version 2
(the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
with the following added to such license:

   As a special exception, the copyright holders of this software give
   you permission to link this software with independent modules, and
   to copy and distribute the resulting executable under terms of your
   choice, provided that you also meet, for each linked independent
   module, the terms and conditions of the license of that module.
   An independent module is a module which is not derived from this
   software.  The special exception does not apply to any modifications
   of the software.

Not withstanding the above, under no circumstances may you combine
this software in any way with any other Broadcom software provided
under a license other than the GPL, without Broadcom's express prior
written consent.

:> 
*/

#ifndef PMC_CPU_CORE_H
#define PMC_CPU_CORE_H

int pmc_cpu_core_power_up(unsigned cpu);
int pmc_cpu_core_power_down(unsigned cpu);
int pmc_cpu_l2cache_power_up(void);
int pmc_cpu_l2cache_power_down(void);
#ifdef CONFIG_BCM963138
int pmc_cpu_neon_power_up(unsigned cpu);
int pmc_cpu_neon_power_down(unsigned cpu);
#endif

#endif //#ifndef PMC_CPU_CORE_H
