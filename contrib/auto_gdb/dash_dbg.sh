#!/usr/bin/env bash
# use testnet settings,  if you need mainnet,  use ~/.dashcore/akaxd.pid file instead
export LC_ALL=C

dash_pid=$(<~/.dashcore/testnet3/akaxd.pid)
sudo gdb -batch -ex "source debug.gdb" akaxd ${dash_pid}
