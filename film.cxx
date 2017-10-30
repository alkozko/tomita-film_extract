#encoding "utf-8"
#GRAMMAR_ROOT S

Title -> Word<h-reg1, quoted>;
Title -> Word<h-reg1, l-quoted, ~r-quoted> Word<~l-quoted, r-quoted>;
Title -> Word<h-reg1, l-quoted, ~r-quoted> AnyWord<~r-quoted>+ Word<~l-quoted, r-quoted>;

GenreDescr -> Word<kwtype="жанр"> | Word<wff=/фильм-.+/> | Adj "фильм";
Genre -> Adj* GenreDescr;
FilmDescriptor -> Genre interp(Film.Genre) | "фильм";

FilmTitle -> Title interp(Film.Name::not_norm);
FilmTitle -> FilmTitle "и" FilmTitle;
S -> FilmTitle Hyphen* FilmDescriptor;
S -> FilmDescriptor FilmTitle;