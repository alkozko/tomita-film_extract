#encoding "utf-8"
#GRAMMAR_ROOT S

Title -> Word<h-reg1, quoted>;
Title -> Word<h-reg1, l-quoted, ~r-quoted> Word<~l-quoted, r-quoted>;
Title -> Word<h-reg1, l-quoted, ~r-quoted> AnyWord<~r-quoted>+ Word<~l-quoted, r-quoted>;

GenreDescr -> Word<kwtype="жанр"> | Word<wff=/фильм-.+/> | Adj "фильм";
Genre -> Adj* GenreDescr;
FilmDescriptor -> Genre interp(Film.Genre) | "фильм";

Name -> Word<h-reg1, ~fw, nc-agr[1]> Word<h-reg1, nc-agr[1]>*;
Director -> Name<gram="род"> interp (Film.Director);

FilmTitle -> Title interp(Film.Name::not_norm);
FilmTitle -> FilmTitle "и" FilmTitle;

S -> FilmTitle Hyphen* FilmDescriptor;
S -> FilmDescriptor (Director) FilmTitle;