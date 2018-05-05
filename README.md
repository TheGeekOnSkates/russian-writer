# Russian Writer

## Introduction and basic usage

I've been learning Russian on duolingo.com (I have the app but prefer the website) and needed a way to easily write Russian characters.  This program turns an English keyboard into a Russian keyboard and back again.  To use it:
1. If you don't have it already, download and install AutoHotKey (probably has to be the Unicode version).
2. Run the script and Bingo!  Your keyboard will write in Russian.
3. To turn Russian Mode on or off, press CTRL+R.

## Next steps

The script works well, at least well enough for me to practice on Duolingo, but I'm planning to port it to C/C++.  This is because:
* AutoHotKey only runs on Windows, and the code could be adapted to fit other platforms if it were in C++.  I don't really know much about Mac or Linux APIs for stuff like this (yet), but I figured maybe one of you guys do.
* AutoHotKey is lightweight and fast, requiring only around 4-5 KB of memory, but I bet I could get it even lighter and faster.
* I felt like a challenge :)