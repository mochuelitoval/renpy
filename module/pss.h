/*
Copyright 2005 PyTom <pytom@bishoujo.us>

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation files
(the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef PSS_H
#define PSS_H

#include <Python.h>
#include <SDL/SDL.h>

SDL_RWops* RWopsFromPythonThreaded(PyObject* obj);


void PSS_play(int channel, SDL_RWops *rw, const char *ext, PyObject *name, int fadeout, int tight, int paused);
void PSS_queue(int channel, SDL_RWops *rw, const char *ext, PyObject *name, int fadeout, int tight);
void PSS_stop(int channel);
void PSS_dequeue(int channel, int even_tight);
int PSS_queue_depth(int channel);
PyObject *PSS_playing_name(int channel);
void PSS_fadeout(int channel, int ms);
void PSS_pause(int channel, int pause);
void PSS_unpause_all(void);
void PSS_set_endevent(int channel, int event);
int PSS_get_pos(int channel);
void PSS_set_volume(int channel, float volume);
float PSS_get_volume(int channel);
void PSS_init(int freq, int stereo, int samples);
void PSS_quit(void);
const char *PSS_get_error(void);

#endif
