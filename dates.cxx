#encoding "utf-8"
#GRAMMAR_ROOT S

Date -> Word<wff="(19[0-9]{2})|(20[0-2][0-9])">;
Descr -> 'год';

S -> Date Descr;