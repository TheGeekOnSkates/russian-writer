﻿# Russian Writer 2.0

## NOTE

* This project is something I wrote several years ago, with an e-mail account that I can't get into anymore.  So future updates will be here, not there.
* I'd also like to share my idea for version 3.0: Linux support.  I found [another GitHub repo](https://github.com/jwmullally/xhklib) demonstrating how to create hotkeys in Linux, and I haven't used Windows (at home) for several years now.  I'm gonna be messing with learning Russian again, so I'll want this to work on Linux.  The Windows version doesn't run under WINE, and this gives me an excuse to take my C/C++ skills up a notch by learning some X11 stuff.


---------------------------------------------------------------------------

## Intro and instructions

I've been learning Russian on duolingo.com (I have the app but prefer the website) and needed a way to easily write Russian characters.  This program turns an English keyboard into a Russian keyboard and back again.  To use it:
1. Clone or download the repo.  The program is pre-compiled in the "Release" folder (russian-writer.exe).
2. Run the program and Bingo!  Your keyboard will write in Russian.
3. To turn Russian Mode on or off, press SHIFT+CTRL+R.

## Contributing
I'm totally open to suggestions, if you want to contribute to this project.  Some ideas might include:
* Building support for other platforms (I'm pretty much a Windows guy; I dabble in Linux but don't know its APIs well enough to do that)
* Changes to make it more like an actual Russian keyboard (I've never actually seen one)
* Writers for other languages!  This was originally Spanish Writer (which I still use every once in awhile) but those are the only languages I know.
* And I know C (obviously) but I'm far from an expert; I would really be interested in ways to simplify it, optimize it, or whatever else would help.

## License

The code relies heavily on the Windows (a.k.a. Win32) API, so it probably has to be under the Microsoft Public License (MS-PL).  I'm not a lawyer, and I'm not gonna pretend to know what I'm talking about in this area, but if I were pressed for an answer I'd go with MS-PL (well personally I'd go with WTFL but that probably can't be used here). :)
