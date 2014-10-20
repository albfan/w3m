# w3m a modern browser for ancient terminals

## Intro

- You love terminals
- You love vim
- You love internet
- You love man pages, but you want to jump files and related man pages.  
- You give up with libcaca ascii image and video viewer (that was cool only for a while)

## Description

w3m is the more close vim experience you can feel browsing internet. Is fast, is simple, is an eyes-saving, and follows some kind of normal/insert mode convention (you just can type text on text input forms, everywhere else keys do something else)

Even more, w3m congrats to offer you a modern pager for man pages:

 - `man bash` refers to *~/.bashrc* for config initialization? You can jump to see that file. 
 - `man perl` refers to http://www.perl.org in SEE ALSO. You can jump to it
 - `man rlwrap` points to readline? You can see that man page directly.

Even, even more

Images and videos are not terminal things, rigth? Well It depends. How owns a real terminal nowadays? In fact all terminals you will ever attemp, are emulators on a powerful graphic machine. So every character you see is a graphic, so in theory, if someone struggling his head, there's a chance to see something graphical on these fake terminals. Well, smart people implement a crazy idea called framebuffer, which allows to show images and videos in some terminals like xterm.

# How this clone was made

Original code comes from sourceforge, and it's on CVS. After made a rsync of all source, cvs2git was used to transform it to git. Then a filter-branch was made to remve CVSROOT and the like. There could be errors, so feel free to contact me to improve this.

If anytime this repo gets obsolete. I will try to make a graft with new changes, so expect this history to be persistent in time (I will not drop it and reimport all changes) But that's only theory, I have never try for real.

## Added features

- autosize manpages:

w3m asumes a 24x80 terminal size. That's cool for a commodore, but is at least aged, these days. With irruption of widescreens, is difficult to set an standard. Luckily, you can interrogate terminal about it's size

    $ echo cols | tput -S

here is an useful alias you can set if compile and install this code

    $ alias man=' w3mman -s $(echo cols | tput -S) '

Try it, and enjoy *goto* `<Enter>` *back* `B`, *search* `/` as you always expect it to be on man pages. 

## Author comments
- If you can read English, see doc/*.
- If you can read Japanese, see doc-jp/*.
- If you can read both, read both and correct English. :-)
