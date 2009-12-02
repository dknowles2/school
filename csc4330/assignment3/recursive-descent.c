/**
 * Recursive descent subprogram for the following EBNF rule:
 *
 * <initializer> -> "{" <designator> { <designator> } = <expression> "}"
 */
void initializer() {
  if (nextToken == "{") {
    lex();

    while (nextToken != "=") {
      designator();
    }

    lex();
    expression();

    if (nextToken == "}") {
      lex();
    } else {
      error();
    }
  } else {
    error();
  }
}
