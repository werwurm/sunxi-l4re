/*
 * (c) 2009 Adam Lackorzynski <adam@os.inf.tu-dresden.de>
 *     economic rights: Technische Universität Dresden (Germany)
 *
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
#ifndef L4_CXX_UART_PL011_H__
#define L4_CXX_UART_PL011_H__

#include "uart_base.h"

namespace L4
{
  class Uart_pl011 : public Uart
  {
  public:
    Uart_pl011(unsigned freq) : _freq(freq) {}
    bool startup(Io_register_block const *);
    void shutdown();
    bool change_mode(Transfer_mode m, Baud_rate r);
    bool enable_rx_irq(bool enable);
    int get_char(bool blocking = true) const;
    int char_avail() const;
    inline void out_char(char c) const;
    int write(char const *s, unsigned long count) const;

  private:
    unsigned _freq;
  };
};

#endif
