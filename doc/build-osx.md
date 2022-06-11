macOS Build Instructions and Notes
====================================
The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

Preparation
-----------
Install the macOS command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

Then install [Homebrew](https://brew.sh).

Base build dependencies
-----------------------

```bash
brew install automake libtool pkg-config libnatpmp
```

If you want to build the disk image with `make deploy` (.dmg / optional), you need RSVG:
```bash
brew install librsvg
```

Building
--------

It's possible that your `PATH` environment variable contains some problematic strings, run
```bash
export PATH=$(echo "$PATH" | sed -e '/\\/!s/ /\\ /g') # fix whitespaces
```

Next, follow the instructions in [build-generic](build-generic.md)

Disable-wallet mode
--------------------
When the intention is to run only a P2P node without a wallet, Akax Core may be compiled in
disable-wallet mode with:

    ./configure --disable-wallet

In this case there is no dependency on Berkeley DB 4.8.

Mining is also possible in disable-wallet mode using the `getblocktemplate` RPC call.

Running
-------

Akax Core is now available at `./src/akaxd`

Before running, you may create an empty configuration file:

    mkdir -p "/Users/${USER}/Library/Application Support/AkaxCore"

    touch "/Users/${USER}/Library/Application Support/AkaxCore/akax.conf"

    chmod 600 "/Users/${USER}/Library/Application Support/AkaxCore/akax.conf"

The first time you run akaxd, it will start downloading the blockchain. This process could take many hours, or even days on slower than average systems.

You can monitor the download process by looking at the debug.log file:

    tail -f $HOME/Library/Application\ Support/AkaxCore/debug.log

Other commands:
-------

    ./src/akaxd -daemon # Starts the akax daemon.
    ./src/akax-cli --help # Outputs a list of command-line options.
    ./src/akax-cli help # Outputs a list of RPC commands when the daemon is running.
