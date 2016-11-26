// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "gen/scratch-code.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "scratch-code.tab.hpp"

// User implementation prologue.

#line 51 "gen/scratch-code.tab.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 35 "src/scratch-code.ypp" // lalr1.cc:413

	#include "ScratchCodeDriver.hpp"

#line 57 "gen/scratch-code.tab.cpp" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 143 "gen/scratch-code.tab.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  ScratchCodeParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  ScratchCodeParser::ScratchCodeParser (ScratchCodeDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  ScratchCodeParser::~ScratchCodeParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  ScratchCodeParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  ScratchCodeParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  ScratchCodeParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  ScratchCodeParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  ScratchCodeParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  ScratchCodeParser::symbol_number_type
  ScratchCodeParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  ScratchCodeParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  ScratchCodeParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 51: // "loop control statement"
        value.move< ast::Lexer::ParsedLoopControlStatement > (that.value);
        break;

      case 50: // "variable type"
        value.move< ast::Lexer::ParsedVariableType > (that.value);
        break;

      case 67: // conditional
      case 68: // conditionalIf
        value.move< std::shared_ptr<ast::Conditional> > (that.value);
        break;

      case 69: // forLoop
        value.move< std::shared_ptr<ast::ForLoop> > (that.value);
        break;

      case 74: // lValue
        value.move< std::shared_ptr<ast::LValue> > (that.value);
        break;

      case 71: // loopControlStatement
        value.move< std::shared_ptr<ast::LoopControlStatement> > (that.value);
        break;

      case 76: // operation
        value.move< std::shared_ptr<ast::Operation> > (that.value);
        break;

      case 75: // rValue
        value.move< std::shared_ptr<ast::RValue> > (that.value);
        break;

      case 52: // "rvalue value"
        value.move< std::shared_ptr<ast::RValueValue> > (that.value);
        break;

      case 60: // statement
        value.move< std::shared_ptr<ast::Statement> > (that.value);
        break;

      case 61: // statements
      case 62: // statementsBlockInternal
      case 63: // statementsBlock
        value.move< std::shared_ptr<ast::StatementList> > (that.value);
        break;

      case 72: // valueStandalone
      case 73: // value
        value.move< std::shared_ptr<ast::Value> > (that.value);
        break;

      case 64: // localVariableDefinition
        value.move< std::shared_ptr<ast::VariableDefinition> > (that.value);
        break;

      case 65: // localVariableDefinitions
      case 66: // localVariableDefinitionList
        value.move< std::shared_ptr<ast::VariableDefinitionList> > (that.value);
        break;

      case 70: // whileLoop
        value.move< std::shared_ptr<ast::WhileLoop> > (that.value);
        break;

      case 49: // "identifier"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  ScratchCodeParser::stack_symbol_type&
  ScratchCodeParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 51: // "loop control statement"
        value.copy< ast::Lexer::ParsedLoopControlStatement > (that.value);
        break;

      case 50: // "variable type"
        value.copy< ast::Lexer::ParsedVariableType > (that.value);
        break;

      case 67: // conditional
      case 68: // conditionalIf
        value.copy< std::shared_ptr<ast::Conditional> > (that.value);
        break;

      case 69: // forLoop
        value.copy< std::shared_ptr<ast::ForLoop> > (that.value);
        break;

      case 74: // lValue
        value.copy< std::shared_ptr<ast::LValue> > (that.value);
        break;

      case 71: // loopControlStatement
        value.copy< std::shared_ptr<ast::LoopControlStatement> > (that.value);
        break;

      case 76: // operation
        value.copy< std::shared_ptr<ast::Operation> > (that.value);
        break;

      case 75: // rValue
        value.copy< std::shared_ptr<ast::RValue> > (that.value);
        break;

      case 52: // "rvalue value"
        value.copy< std::shared_ptr<ast::RValueValue> > (that.value);
        break;

      case 60: // statement
        value.copy< std::shared_ptr<ast::Statement> > (that.value);
        break;

      case 61: // statements
      case 62: // statementsBlockInternal
      case 63: // statementsBlock
        value.copy< std::shared_ptr<ast::StatementList> > (that.value);
        break;

      case 72: // valueStandalone
      case 73: // value
        value.copy< std::shared_ptr<ast::Value> > (that.value);
        break;

      case 64: // localVariableDefinition
        value.copy< std::shared_ptr<ast::VariableDefinition> > (that.value);
        break;

      case 65: // localVariableDefinitions
      case 66: // localVariableDefinitionList
        value.copy< std::shared_ptr<ast::VariableDefinitionList> > (that.value);
        break;

      case 70: // whileLoop
        value.copy< std::shared_ptr<ast::WhileLoop> > (that.value);
        break;

      case 49: // "identifier"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  ScratchCodeParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  ScratchCodeParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 49: // "identifier"

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::string > ()).name() << " at " << &yysym.value.template as< std::string > (); }
#line 448 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 50: // "variable type"

#line 108 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << ast::Lexer::getParsedVariableTypeString(yysym.value.template as< ast::Lexer::ParsedVariableType > ()); }
#line 455 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 51: // "loop control statement"

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< ast::Lexer::ParsedLoopControlStatement > ()).name() << " at " << &yysym.value.template as< ast::Lexer::ParsedLoopControlStatement > (); }
#line 462 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 52: // "rvalue value"

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::RValueValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::RValueValue> > (); }
#line 469 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 60: // statement

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Statement> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Statement> > (); }
#line 476 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 61: // statements

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 483 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 62: // statementsBlockInternal

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 490 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 63: // statementsBlock

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 497 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 64: // localVariableDefinition

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > (); }
#line 504 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 65: // localVariableDefinitions

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 511 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 66: // localVariableDefinitionList

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 518 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 67: // conditional

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Conditional> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Conditional> > (); }
#line 525 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 68: // conditionalIf

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Conditional> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Conditional> > (); }
#line 532 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 69: // forLoop

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ForLoop> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ForLoop> > (); }
#line 539 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 70: // whileLoop

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::WhileLoop> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::WhileLoop> > (); }
#line 546 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 71: // loopControlStatement

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::LoopControlStatement> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::LoopControlStatement> > (); }
#line 553 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 72: // valueStandalone

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Value> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Value> > (); }
#line 560 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 73: // value

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Value> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Value> > (); }
#line 567 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 74: // lValue

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::LValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::LValue> > (); }
#line 574 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 75: // rValue

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::RValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::RValue> > (); }
#line 581 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 76: // operation

#line 109 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Operation> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Operation> > (); }
#line 588 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  ScratchCodeParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  ScratchCodeParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  ScratchCodeParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  ScratchCodeParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  ScratchCodeParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  ScratchCodeParser::debug_level_type
  ScratchCodeParser::debug_level () const
  {
    return yydebug_;
  }

  void
  ScratchCodeParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline ScratchCodeParser::state_type
  ScratchCodeParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  ScratchCodeParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  ScratchCodeParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  ScratchCodeParser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 23 "src/scratch-code.ypp" // lalr1.cc:741
{
	//initialize the initial location (@$ evaluates to "yyla.location", thus it is not directly associated with my code)
	//"yyla" is in gen/scratch-code.tab.cpp and is a "symbol_type"=instance of "basic_symbol<by_type>" templated class
	//"basic_symbol" class contains member "location" of type "location_type"=instance of "location" class
	//"location" class is in gen/location.hh, has "begin" and "end" members of type "position"
	//"position" class is in gen/position.hh, has "filename" member of type std::string*
	yyla.location.begin.filename = yyla.location.end.filename = driver.getFilenamePointer();
}

#line 711 "gen/scratch-code.tab.cpp" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 51: // "loop control statement"
        yylhs.value.build< ast::Lexer::ParsedLoopControlStatement > ();
        break;

      case 50: // "variable type"
        yylhs.value.build< ast::Lexer::ParsedVariableType > ();
        break;

      case 67: // conditional
      case 68: // conditionalIf
        yylhs.value.build< std::shared_ptr<ast::Conditional> > ();
        break;

      case 69: // forLoop
        yylhs.value.build< std::shared_ptr<ast::ForLoop> > ();
        break;

      case 74: // lValue
        yylhs.value.build< std::shared_ptr<ast::LValue> > ();
        break;

      case 71: // loopControlStatement
        yylhs.value.build< std::shared_ptr<ast::LoopControlStatement> > ();
        break;

      case 76: // operation
        yylhs.value.build< std::shared_ptr<ast::Operation> > ();
        break;

      case 75: // rValue
        yylhs.value.build< std::shared_ptr<ast::RValue> > ();
        break;

      case 52: // "rvalue value"
        yylhs.value.build< std::shared_ptr<ast::RValueValue> > ();
        break;

      case 60: // statement
        yylhs.value.build< std::shared_ptr<ast::Statement> > ();
        break;

      case 61: // statements
      case 62: // statementsBlockInternal
      case 63: // statementsBlock
        yylhs.value.build< std::shared_ptr<ast::StatementList> > ();
        break;

      case 72: // valueStandalone
      case 73: // value
        yylhs.value.build< std::shared_ptr<ast::Value> > ();
        break;

      case 64: // localVariableDefinition
        yylhs.value.build< std::shared_ptr<ast::VariableDefinition> > ();
        break;

      case 65: // localVariableDefinitions
      case 66: // localVariableDefinitionList
        yylhs.value.build< std::shared_ptr<ast::VariableDefinitionList> > ();
        break;

      case 70: // whileLoop
        yylhs.value.build< std::shared_ptr<ast::WhileLoop> > ();
        break;

      case 49: // "identifier"
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 133 "src/scratch-code.ypp" // lalr1.cc:859
    {
		*(driver.parsedStatementList) = *(yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ());
		
		for(auto stmt : driver.parsedStatementList->getStatements())
		{
			//loop control statements are always invalid here, because there can be no loop statement block on the very first level
			if(stmt->isA<ast::LoopControlStatement>())
				throw yy::ScratchCodeParser::syntax_error(driver.loopControlStatementLocations.at(std::static_pointer_cast<ast::LoopControlStatement>(stmt)), "loop control statement has no loop to target");
		
			//parents of statements on first level need to be assigned manually here (as "unit" expects "statements" and not "statementsBlock")
			stmt->setParent(driver.parsedStatementList);
		}
		
		
	}
#line 904 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 152 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::Value> > (); }
#line 910 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 153 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::Conditional> > (); }
#line 916 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 154 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::ForLoop> > (); }
#line 922 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 155 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::WhileLoop> > (); }
#line 928 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 156 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::LoopControlStatement> > (); }
#line 934 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 159 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = std::make_shared<ast::StatementList>(nullptr);
	}
#line 942 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 163 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ()->addStatement(yystack_[0].value.as< std::shared_ptr<ast::Statement> > ());
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 951 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 168 "src/scratch-code.ypp" // lalr1.cc:859
    {
		for(auto varDef : yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs())
			yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ()->addStatement(varDef);
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 961 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 175 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 969 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 179 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newStmtList = std::make_shared<ast::StatementList>(nullptr);
		newStmtList->addStatement(yystack_[0].value.as< std::shared_ptr<ast::Statement> > ());
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = newStmtList;
	}
#line 979 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 186 "src/scratch-code.ypp" // lalr1.cc:859
    {
		for(auto stmt : yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->getStatements())
			stmt->setParent(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		
		//clean up variable definitions that went out of scope
		auto i = driver.variableDefinitions.begin();
		while(i != driver.variableDefinitions.end())
		{
			if((*i)->hasParent<ast::StatementList>(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()))
				i = driver.variableDefinitions.erase(i);
			else
				++i;
		}
		
		//set target loops for loop control statements
		for(auto stmt : yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->getStatements())
		{
			if(stmt->isA<ast::LoopControlStatement>())
			{
				auto lcs = std::static_pointer_cast<ast::LoopControlStatement>(stmt);
				auto parentLoop = lcs->hasParentWithIdBase<ast::ControllableLoop>();
				if(parentLoop == nullptr)
					throw yy::ScratchCodeParser::syntax_error(driver.loopControlStatementLocations.at(lcs), "loop control statement has no loop to target");
				else
				{
					lcs->setTargetLoop(parentLoop);
					driver.loopControlStatementLocations.erase(lcs);
				}
			}
		}
		
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 1017 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 224 "src/scratch-code.ypp" // lalr1.cc:859
    {
		if(std::find_if(driver.variableDefinitions.begin(), driver.variableDefinitions.end(), [&](auto& varDef) { return (varDef->getName() == yystack_[0].value.as< std::string > ()); }) != driver.variableDefinitions.end())
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "'" + yystack_[0].value.as< std::string > () + "' is already declared");
		yylhs.value.as< std::shared_ptr<ast::VariableDefinition> > () = std::make_shared<ast::VariableDefinition>(nullptr, ast::Lexer::ParsedVariableType::Invalid, yystack_[0].value.as< std::string > ());
	}
#line 1027 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 231 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = std::make_shared<ast::VariableDefinitionList>(nullptr);
	}
#line 1035 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 235 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->addVarDef(yystack_[0].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1044 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 241 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().insert(yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().begin(), yystack_[2].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		for(auto varDef : yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs())
		{
			varDef->setType(yystack_[3].value.as< ast::Lexer::ParsedVariableType > ());
			driver.variableDefinitions.push_back(varDef);
		}
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1058 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 255 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = yystack_[0].value.as< std::shared_ptr<ast::Conditional> > ();
	}
#line 1066 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 259 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ());
		yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ()->setAlternativeBody(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ();
	}
#line 1076 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 266 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newCond = std::make_shared<ast::Conditional>(nullptr);
		yystack_[2].value.as< std::shared_ptr<ast::Value> > ()->setParent(newCond);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newCond);
		newCond->addCondition(yystack_[2].value.as< std::shared_ptr<ast::Value> > ());
		newCond->addConsequenceBody(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = newCond;
	}
#line 1089 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 276 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newForLoop = std::make_shared<ast::ForLoop>(nullptr, yystack_[6].value.as< std::shared_ptr<ast::Value> > (), yystack_[4].value.as< std::shared_ptr<ast::Value> > (), yystack_[2].value.as< std::shared_ptr<ast::Value> > (), yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yystack_[6].value.as< std::shared_ptr<ast::Value> > ()->setParent(newForLoop);
		yystack_[4].value.as< std::shared_ptr<ast::Value> > ()->setParent(newForLoop);
		yystack_[2].value.as< std::shared_ptr<ast::Value> > ()->setParent(newForLoop);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newForLoop);
		yylhs.value.as< std::shared_ptr<ast::ForLoop> > () = newForLoop;
	}
#line 1102 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 286 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newWhileLoop = std::make_shared<ast::WhileLoop>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yystack_[2].value.as< std::shared_ptr<ast::Value> > ()->setParent(newWhileLoop);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newWhileLoop);
		yylhs.value.as< std::shared_ptr<ast::WhileLoop> > () = newWhileLoop;
	}
#line 1113 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 294 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newLCS = std::make_shared<ast::LoopControlStatement>(nullptr, yystack_[1].value.as< ast::Lexer::ParsedLoopControlStatement > (), nullptr);
		driver.loopControlStatementLocations[newLCS] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::LoopControlStatement> > () = newLCS;
	}
#line 1123 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 304 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[1].value.as< std::shared_ptr<ast::Value> > ();
	}
#line 1131 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 308 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::LValue> > (); }
#line 1137 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 309 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::RValue> > (); }
#line 1143 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 311 "src/scratch-code.ypp" // lalr1.cc:859
    {
		if(yystack_[0].value.as< std::shared_ptr<ast::Operation> > ()->isA<ast::UnaryOperation>())
		{
			auto unOp = std::static_pointer_cast<ast::UnaryOperation>(yystack_[0].value.as< std::shared_ptr<ast::Operation> > ());
			auto valCat = unOp->getValue()->getValueCategory();
			auto reqValCat = unOp->getRequiredValueCategory();
			if(reqValCat != ast::Lexer::ValueCategory::Any  &&  reqValCat != valCat)
				throw yy::ScratchCodeParser::syntax_error(yylhs.location, "unexpected " + ast::Lexer::getValueCategoryString(valCat) + " for value of " + ast::Lexer::getParsedUnaryOperationString(unOp->getOperation()) + ", expected " + ast::Lexer::getValueCategoryString(reqValCat));
			unOp->getValue()->setParent(unOp);
			yylhs.value.as< std::shared_ptr<ast::Value> > () = unOp;
		}
		else if(yystack_[0].value.as< std::shared_ptr<ast::Operation> > ()->isA<ast::BinaryOperation>())
		{
			auto binOp = std::static_pointer_cast<ast::BinaryOperation>(yystack_[0].value.as< std::shared_ptr<ast::Operation> > ());
			auto lhsValCat = binOp->getLhs()->getValueCategory(), rhsValCat = binOp->getRhs()->getValueCategory();
			auto lhsReqValCat = binOp->getRequiredLhsValueCategory(), rhsReqValCat = binOp->getRequiredRhsValueCategory();
			if(lhsReqValCat != ast::Lexer::ValueCategory::Any  &&  lhsReqValCat != lhsValCat)
				throw yy::ScratchCodeParser::syntax_error(yylhs.location, "unexpected " + ast::Lexer::getValueCategoryString(lhsValCat) + " for left hand side of " + ast::Lexer::getParsedBinaryOperationString(binOp->getOperation()) + ", expected " + ast::Lexer::getValueCategoryString(lhsReqValCat));
			if(rhsReqValCat != ast::Lexer::ValueCategory::Any  &&  rhsReqValCat != rhsValCat)
				throw yy::ScratchCodeParser::syntax_error(yylhs.location, "unexpected " + ast::Lexer::getValueCategoryString(rhsValCat) + " for right hand side of " + ast::Lexer::getParsedBinaryOperationString(binOp->getOperation()) + ", expected " + ast::Lexer::getValueCategoryString(rhsReqValCat));
			binOp->getLhs()->setParent(binOp);
			binOp->getRhs()->setParent(binOp);
			yylhs.value.as< std::shared_ptr<ast::Value> > () = binOp;
		}
		else
		{
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "fatal inconsistency error");
		}
	}
#line 1177 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 341 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[1].value.as< std::shared_ptr<ast::Value> > ();
	}
#line 1185 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 346 "src/scratch-code.ypp" // lalr1.cc:859
    {
		std::vector<std::shared_ptr<ast::VariableDefinition>>::iterator assocVarDef = std::find_if(driver.variableDefinitions.begin(), driver.variableDefinitions.end(), [&](auto& varDef) { return (varDef->getName() == yystack_[0].value.as< std::string > ()); });
		if(assocVarDef == driver.variableDefinitions.end())
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "'" + yystack_[0].value.as< std::string > () + "' was not declared in this scope");
		yylhs.value.as< std::shared_ptr<ast::LValue> > () = std::make_shared<ast::LValue>(nullptr, *assocVarDef);
	}
#line 1196 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 353 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::RValue> > () = yystack_[0].value.as< std::shared_ptr<ast::RValueValue> > (); }
#line 1202 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 359 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Assignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1208 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 360 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::AddAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1214 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 361 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::SubtractAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1220 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 362 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::MultiplyAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1226 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 363 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::DivideAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1232 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 364 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::ModuloAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1238 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 365 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseAndAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1244 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 366 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseOrAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1250 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 367 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseXorAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1256 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 368 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftLeftAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1262 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 369 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftRightAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1268 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 370 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LogicalOr, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1274 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 371 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LogicalAnd, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1280 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 372 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseOr, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1286 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 373 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseXor, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1292 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 374 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseAnd, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1298 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 375 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Equal, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1304 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 376 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::NotEqual, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1310 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 377 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LessThan, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1316 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 378 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LessThanOrEqual, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1322 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 379 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::GreaterThan, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1328 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 380 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::GreaterThanOrEqual, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1334 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 381 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftLeft, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1340 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 382 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftRight, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1346 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 383 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Add, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1352 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 384 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Subtract, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1358 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 385 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Multiply, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1364 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 386 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Divide, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1370 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 387 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Modulo, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1376 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 388 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PrefixIncrement, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1382 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 389 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PrefixDecrement, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1388 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 390 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::UnaryPlus, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1394 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 391 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::UnaryMinus, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1400 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 392 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::LogicalNot, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1406 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 393 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::BitwiseNot, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1412 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 394 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PostfixIncrement, yystack_[1].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1418 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 395 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PostfixDecrement, yystack_[1].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1424 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;


#line 1428 "gen/scratch-code.tab.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  ScratchCodeParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  ScratchCodeParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char ScratchCodeParser::yypact_ninf_ = -88;

  const signed char ScratchCodeParser::yytable_ninf_ = -1;

  const short int
  ScratchCodeParser::yypact_[] =
  {
     -88,    12,    70,   -88,   -88,    10,    11,    28,   139,   139,
     139,   139,   139,   139,   139,   -88,   -36,    22,   -88,   -88,
     -88,   -88,    36,   -88,   -88,   -88,   -88,   330,   -88,   -88,
     -88,   139,   139,   139,   176,   -10,   -10,   -10,   -10,   -10,
     -10,   -88,   -88,   -88,   121,   -88,   139,   139,   -88,   -88,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   216,   256,   364,
     -88,    -4,   -88,   -88,   -88,   -88,    61,    61,   -10,   -10,
     -10,    -2,   508,   530,   145,   145,   486,   464,   158,   158,
     158,   158,   552,   552,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   121,   121,   139,   -36,   -88,
      94,   -88,   -88,   398,   -88,   -88,   139,   296,   121,   -88
  };

  const unsigned char
  ScratchCodeParser::yydefact_[] =
  {
       8,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,    30,     9,
      10,     4,    18,     5,     6,     7,     3,     0,    25,    26,
      27,     0,     0,     0,     0,    62,    63,    60,    61,    64,
      65,    14,    15,    23,     0,    24,     0,     0,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     8,    12,    13,    19,    55,    56,    57,    58,
      59,    46,    44,    45,    53,    54,    43,    42,    49,    50,
      51,    52,    47,    48,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,     0,    17,
       0,    20,    22,     0,    16,    11,     0,     0,     0,    21
  };

  const signed char
  ScratchCodeParser::yypgoto_[] =
  {
     -88,   -88,     5,   -13,   -88,   -87,   -47,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,    -8,   -88,   -88,   -88
  };

  const signed char
  ScratchCodeParser::yydefgoto_[] =
  {
      -1,     1,    83,     2,    84,    85,    42,    81,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30
  };

  const unsigned char
  ScratchCodeParser::yytable_[] =
  {
      34,    35,    36,    37,    38,    39,    40,    19,    48,    49,
     118,   119,     3,    41,    46,    47,    48,    49,    31,    32,
      50,    51,    52,    77,    78,    79,    56,    57,   121,   122,
      60,    61,    62,    63,    64,    65,    33,    43,    86,    87,
      44,   129,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   120,
       4,   124,     0,     5,     0,     6,     7,     0,     8,    48,
      49,     0,     0,    50,    51,    52,     9,    10,    11,    12,
      13,    14,     0,     0,     0,     0,     0,     5,     0,     6,
       7,     0,     8,     0,     0,     0,     0,   125,     0,   123,
       9,    10,    11,    12,    13,    14,     0,     0,   127,    15,
      16,    17,    18,     0,     5,    19,     6,     7,     0,     8,
       0,     0,     0,    82,     0,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     8,     0,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    46,    47,    48,    49,     0,     0,    50,    51,    52,
      15,     0,    17,    18,    46,    47,    48,    49,     0,     0,
      50,    51,    52,     0,     0,    80,    56,    57,    15,     0,
       0,    18,    46,    47,    48,    49,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,   115,     0,     0,     0,     0,
       0,     0,    46,    47,    48,    49,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,   116,     0,     0,     0,     0,
       0,     0,    46,    47,    48,    49,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,   128,     0,     0,     0,     0,
       0,     0,    46,    47,    48,    49,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    45,    46,    47,    48,    49,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   117,
      46,    47,    48,    49,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   126,    46,    47,    48,    49,     0,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    46,    47,    48,
      49,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      46,    47,    48,    49,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,    60,    61,    62,    63,
      64,    65,    46,    47,    48,    49,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,    60,    61,
      62,    63,    64,    65,    46,    47,    48,    49,     0,     0,
      50,    51,    52,    53,     0,    55,    56,    57,     0,     0,
      60,    61,    62,    63,    64,    65,    46,    47,    48,    49,
       0,     0,    50,    51,    52,    53,     0,     0,    56,    57,
       0,     0,    60,    61,    62,    63,    64,    65,    46,    47,
      48,    49,     0,     0,    50,    51,    52,     0,     0,     0,
      56,    57,     0,     0,    60,    61,    62,    63
  };

  const short int
  ScratchCodeParser::yycheck_[] =
  {
       8,     9,    10,    11,    12,    13,    14,     2,    18,    19,
      14,    15,     0,    49,    16,    17,    18,    19,     8,     8,
      22,    23,    24,    31,    32,    33,    28,    29,   115,   116,
      32,    33,    34,    35,    36,    37,     8,    15,    46,    47,
       4,   128,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    82,
       0,   118,    -1,     3,    -1,     5,     6,    -1,     8,    18,
      19,    -1,    -1,    22,    23,    24,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    13,    -1,   117,
      16,    17,    18,    19,    20,    21,    -1,    -1,   126,    49,
      50,    51,    52,    -1,     3,   120,     5,     6,    -1,     8,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21,    49,    50,    51,    52,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      49,    -1,    51,    52,    16,    17,    18,    19,    -1,    -1,
      22,    23,    24,    -1,    -1,     9,    28,    29,    49,    -1,
      -1,    52,    16,    17,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    15,    16,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    15,    16,    17,    18,    19,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    16,    17,    18,
      19,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    16,    17,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    16,    17,    18,    19,    -1,    -1,
      22,    23,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    16,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    16,    17,
      18,    19,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    33,    34,    35
  };

  const unsigned char
  ScratchCodeParser::yystos_[] =
  {
       0,    59,    61,     0,     0,     3,     5,     6,     8,    16,
      17,    18,    19,    20,    21,    49,    50,    51,    52,    60,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,     8,     8,     8,    73,    73,    73,    73,    73,    73,
      73,    49,    64,    15,     4,    15,    16,    17,    18,    19,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    73,    73,    73,
       9,    65,    12,    60,    62,    63,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,     9,     9,    15,    14,    15,
      61,    63,    63,    73,    64,    13,    15,    73,     9,    63
  };

  const unsigned char
  ScratchCodeParser::yyr1_[] =
  {
       0,    58,    59,    60,    60,    60,    60,    60,    61,    61,
      61,    62,    62,    63,    64,    65,    65,    66,    67,    67,
      68,    69,    70,    71,    72,    73,    73,    73,    73,    74,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76
  };

  const unsigned char
  ScratchCodeParser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     0,     2,
       2,     3,     1,     1,     1,     0,     3,     4,     1,     3,
       5,     9,     5,     2,     2,     1,     1,     1,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const ScratchCodeParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"if\"", "\"else\"",
  "\"while\"", "\"for\"", "\"return\"", "\"(\"", "\")\"", "\"[\"", "\"]\"",
  "\"{\"", "\"}\"", "\",\"", "\";\"", "\"+\"", "\"-\"", "\"++\"", "\"--\"",
  "\"!\"", "\"~\"", "\"*\"", "\"/\"", "\"%\"", "\"&\"", "\"|\"", "\"^\"",
  "\"<<\"", "\">>\"", "\"&&\"", "\"||\"", "\"<\"", "\"<=\"", "\">\"",
  "\">=\"", "\"==\"", "\"!=\"", "\"=\"", "\"+=\"", "\"-=\"", "\"*=\"",
  "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"", "\"^=\"", "\"<<=\"", "\">>=\"",
  "\"identifier\"", "\"variable type\"", "\"loop control statement\"",
  "\"rvalue value\"", "\"then\"", "UNOP_UNARY_PLUS", "UNOP_UNARY_MINUS",
  "UNOP_POSTFIX_INCREMENT", "UNOP_POSTFIX_DECREMENT", "$accept", "unit",
  "statement", "statements", "statementsBlockInternal", "statementsBlock",
  "localVariableDefinition", "localVariableDefinitions",
  "localVariableDefinitionList", "conditional", "conditionalIf", "forLoop",
  "whileLoop", "loopControlStatement", "valueStandalone", "value",
  "lValue", "rValue", "operation", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  ScratchCodeParser::yyrline_[] =
  {
       0,   132,   132,   152,   153,   154,   155,   156,   158,   162,
     167,   174,   178,   185,   223,   230,   234,   240,   254,   258,
     265,   275,   285,   293,   303,   308,   309,   310,   340,   345,
     353,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395
  };

  // Print the state stack on the debug stream.
  void
  ScratchCodeParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  ScratchCodeParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1976 "gen/scratch-code.tab.cpp" // lalr1.cc:1167
#line 396 "src/scratch-code.ypp" // lalr1.cc:1168




#include "Main.hpp"

void yy::ScratchCodeParser::error(const location_type& loc, const std::string& message)
{
	driver.handleError(loc, message);
}

