#encoding "utf-8"
#GRAMMAR_ROOT S

Title -> Word<h-reg1, quoted>;
Title -> Word<h-reg1, l-quoted, ~r-quoted> Word<~l-quoted, r-quoted>;
Title -> Word<h-reg1, l-quoted, ~r-quoted> AnyWord<~r-quoted>+ Word<~l-quoted, r-quoted>;

S -> Title;