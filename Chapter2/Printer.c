/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include "Printer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INDENT_WIDTH 2

int _n_;
char* buf_;
int cur_;
int buf_size;

/* You may wish to change the renderC functions */
void renderC(Char c)
{
  if (c == '{')
  {
     bufAppendC('\n');
     indent();
     bufAppendC(c);
     _n_ = _n_ + INDENT_WIDTH;
     bufAppendC('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppendC(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppendC(c);
  }
  else if (c == '}')
  {
     int t;
     _n_ = _n_ - INDENT_WIDTH;
     for(t=0; t<INDENT_WIDTH; t++) {
       backup();
     }
     bufAppendC(c);
     bufAppendC('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppendC(c);
     bufAppendC(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppendC(c);
     bufAppendC('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppendC(' ');
     bufAppendC(c);
     bufAppendC(' ');
  }
}
void renderS(String s)
{
  if(strlen(s) > 0)
  {
    bufAppendS(s);
    bufAppendC(' ');
  }
}
void indent(void)
{
  int n = _n_;
  while (n > 0)
  {
    bufAppendC(' ');
    n--;
  }
}
void backup(void)
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
char* printExp(Exp p)
{
  _n_ = 0;
  bufReset();
  ppExp(p, 0);
  return buf_;
}
char* showExp(Exp p)
{
  _n_ = 0;
  bufReset();
  shExp(p);
  return buf_;
}
void ppExp(Exp _p_, int _i_)
{
  switch(_p_->kind)
  {
  case is_EAdd:
    if (_i_ > 0) renderC(_L_PAREN);
    ppExp(_p_->u.eadd_.exp_1, 0);
    renderC('+');
    ppExp(_p_->u.eadd_.exp_2, 1);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_ESub:
    if (_i_ > 0) renderC(_L_PAREN);
    ppExp(_p_->u.esub_.exp_1, 0);
    renderC('-');
    ppExp(_p_->u.esub_.exp_2, 1);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_EMul:
    if (_i_ > 1) renderC(_L_PAREN);
    ppExp(_p_->u.emul_.exp_1, 1);
    renderC('*');
    ppExp(_p_->u.emul_.exp_2, 2);

    if (_i_ > 1) renderC(_R_PAREN);
    break;

  case is_EDiv:
    if (_i_ > 1) renderC(_L_PAREN);
    ppExp(_p_->u.ediv_.exp_1, 1);
    renderC('/');
    ppExp(_p_->u.ediv_.exp_2, 2);

    if (_i_ > 1) renderC(_R_PAREN);
    break;

  case is_EInt:
    if (_i_ > 2) renderC(_L_PAREN);
    ppInteger(_p_->u.eint_.integer_, 0);

    if (_i_ > 2) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Exp!\n");
    exit(1);
  }
}

void ppInteger(Integer n, int i)
{
  char tmp[16];
  sprintf(tmp, "%d", n);
  bufAppendS(tmp);
}
void ppDouble(Double d, int i)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppendS(tmp);
}
void ppChar(Char c, int i)
{
  bufAppendC('\'');
  bufAppendC(c);
  bufAppendC('\'');
}
void ppString(String s, int i)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}
void ppIdent(String s, int i)
{
  renderS(s);
}

void shExp(Exp _p_)
{
  switch(_p_->kind)
  {
  case is_EAdd:
  bufAppendC('(');

    bufAppendS("EAdd");

  bufAppendC(' ');

    shExp(_p_->u.eadd_.exp_1);
  bufAppendC(' ');
    shExp(_p_->u.eadd_.exp_2);

  bufAppendC(')');

    break;

  case is_ESub:
  bufAppendC('(');

    bufAppendS("ESub");

  bufAppendC(' ');

    shExp(_p_->u.esub_.exp_1);
  bufAppendC(' ');
    shExp(_p_->u.esub_.exp_2);

  bufAppendC(')');

    break;

  case is_EMul:
  bufAppendC('(');

    bufAppendS("EMul");

  bufAppendC(' ');

    shExp(_p_->u.emul_.exp_1);
  bufAppendC(' ');
    shExp(_p_->u.emul_.exp_2);

  bufAppendC(')');

    break;

  case is_EDiv:
  bufAppendC('(');

    bufAppendS("EDiv");

  bufAppendC(' ');

    shExp(_p_->u.ediv_.exp_1);
  bufAppendC(' ');
    shExp(_p_->u.ediv_.exp_2);

  bufAppendC(')');

    break;

  case is_EInt:
  bufAppendC('(');

    bufAppendS("EInt");

  bufAppendC(' ');

    bufAppendC('[');
    shInteger(_p_->u.eint_.integer_);
    bufAppendC(']');

  bufAppendC(')');

    break;


  default:
    fprintf(stderr, "Error: bad kind field when showing Exp!\n");
    exit(1);
  }
}

void shInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppendS(tmp);
}
void shDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppendS(tmp);
}
void shChar(Char c)
{
  bufAppendC('\'');
  bufAppendC(c);
  bufAppendC('\'');
}
void shString(String s)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}
void shIdent(String s)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}

void bufAppendS(const char* s)
{
  int len = strlen(s);
  int n;
  while (cur_ + len > buf_size)
  {
    buf_size *= 2; /* Double the buffer size */
    resizeBuffer();
  }
  for(n = 0; n < len; n++)
  {
    buf_[cur_ + n] = s[n];
  }
  cur_ += len;
  buf_[cur_] = 0;
}
void bufAppendC(const char c)
{
  if (cur_ == buf_size)
  {
    buf_size *= 2; /* Double the buffer size */
    resizeBuffer();
  }
  buf_[cur_] = c;
  cur_++;
  buf_[cur_] = 0;
}
void bufReset(void)
{
  cur_ = 0;
  buf_size = BUFFER_INITIAL;
  resizeBuffer();
  memset(buf_, 0, buf_size);
}
void resizeBuffer(void)
{
  char* temp = (char*) malloc(buf_size);
  if (!temp)
  {
    fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
    exit(1);
  }
  if (buf_)
  {
    strncpy(temp, buf_, buf_size); /* peteg: strlcpy is safer, but not POSIX/ISO C. */
    free(buf_);
  }
  buf_ = temp;
}
char *buf_;
int cur_, buf_size;

