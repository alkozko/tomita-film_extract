#encoding "utf-8"
#GRAMMAR_ROOT S

Date -> Word<wff="(19[0-9]{2})|(20[0-2][0-9])">;
Descr -> 'год';

Day -> Word<wff="([0-3]?[0-9])">;
DayDescr -> "январь" | "февраль" | "март" | "апрель" | "май" | "июнь" |  "июль" | "август" | "сентябрь" | "октябрь" | "ноябрь" | "декабрь"; 
FullDay -> Day DayDescr;

S -> (FullDay) Date Descr;