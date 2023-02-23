# dwmblocks

A [`dwm`](https://dwm.suckless.org) status bar that has a modular, async design, so it is always responsive.

## Features
- [Modular](#modifying-the-blocks)
- Lightweight
- [Suckless](https://suckless.org/philosophy)
- Blocks:
    - Loaded asynchronously
    - [Updates can be externally triggered](#signalling-changes)
- Compatible with `i3blocks` scripts

> Additionally, this build of `dwmblocks` is more optimized and fixes the flickering of the status bar when scrolling.

## Why `dwmblocks-async`?
The magic of `dwmblocks-async` is in the `async` part. Since vanilla `dwmblocks` executes the commands of each block sequentially, it leads to annoying freezes. In cases where one block takes several seconds to execute, like in the mail and date blocks example from above, the delay is clearly visible. Fire up a new instance of `dwmblocks` and you'll see!

With `dwmblocks-async`, the computer executes each block asynchronously (simultaneously).

## Usage
To set `dwmblocks-async` as your status bar, you need to run it as a background process on startup. One way is to add the following to `~/.xinitrc`:

```sh
# The binary of `dwmblocks` is named `dwmblocks`
dwmblocks &
```

### Modifying the blocks
You can define your status bar blocks in `config.h`:

```c
const Block blocks[] = {
    ...
    BLOCK("volume", 0, 10),
    BLOCK("clock",  1, 1),
    ...
};
```

Each block has the following properties:

Property|Description
-|-
Command | The command you wish to execute in your block.
Update interval | Time in seconds, after which you want the block to update. If `0`, the block will never be updated.
Update signal | Signal to be used for triggering the block. Must be a positive integer. If `0`, a signal won't be set up for the block and it will be unclickable.

### Signalling changes
Most status bars constantly rerun all scripts every few seconds. This is an option here, but a superior choice is to give your block a signal through which you can indicate it to update on relevant event, rather than have it rerun idly.

For example, the volume block has the update signal `10` by default. I run `kill -44 $(pidof dwmblocks)` alongside my volume shortcuts in `dwm` to only update it when relevant. Just add `34` to your signal number! You could also run `pkill -RTMIN+10 dwmblocks`, but it's slower.

To refresh all the blocks, run `kill -10 $(pidof dwmblocks)` or `pkill -SIGUSR1 dwmblocks`.

> All blocks must have different signal numbers!

## Installation
Clone this repository, modify `config.h` appropriately, then compile the program:

```sh
git clone https://github.com/thatguynoe/dwmblocks
cd dwmblocks
sudo make install
```
