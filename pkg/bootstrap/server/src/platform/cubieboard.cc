/*!
 * \file   cubieboard.cc
 * \brief  Support for the cubieboard.org
 *
 * \date   2013-01
 * \author Janis Danisevskis <janis@sec.t-labs.tu-berlin.de>
 *
 */

#include "support.h"
#include <l4/drivers/uart_omap35x.h>

namespace {
class Platform_cubieboard : public Platform_single_region_ram
{
  bool probe() { return true; }

  void init()
  {
    static L4::Uart_omap35x _uart;
    static L4::Io_register_block_mmio r(0x01c28000);
    
    _uart.startup(&r);
    set_stdio_uart(&_uart);
  }
};
}

REGISTER_PLATFORM(Platform_cubieboard);
