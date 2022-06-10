#!/usr/bin/env bash
# use testnet settings,  if you need mainnet,  use ~/.dashcore/xeked.pid file instead
export LC_ALL=C

dash_pid=$(<~/.dashcore/testnet3/xeked.pid)
sudo gdb -batch -ex "source debug.gdb" xeked ${dash_pid}
