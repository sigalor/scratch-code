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
#line 56 "src/scratch-code.ypp" // lalr1.cc:413

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
      case 55: // "loop control statement"
        value.move< ast::Lexer::ParsedLoopControlStatement > (that.value);
        break;

      case 54: // "variable type"
        value.move< ast::Lexer::ParsedVariableType > (that.value);
        break;

      case 71: // conditional
      case 72: // conditionalIf
        value.move< std::shared_ptr<ast::Conditional> > (that.value);
        break;

      case 74: // forLoop
        value.move< std::shared_ptr<ast::ForLoop> > (that.value);
        break;

      case 86: // functionCall
        value.move< std::shared_ptr<ast::FunctionCall> > (that.value);
        break;

      case 77: // functionDefinition
        value.move< std::shared_ptr<ast::FunctionDefinition> > (that.value);
        break;

      case 84: // lValue
        value.move< std::shared_ptr<ast::LValue> > (that.value);
        break;

      case 76: // loopControlStatement
        value.move< std::shared_ptr<ast::LoopControlStatement> > (that.value);
        break;

      case 89: // operation
        value.move< std::shared_ptr<ast::Operation> > (that.value);
        break;

      case 85: // rValue
        value.move< std::shared_ptr<ast::RValue> > (that.value);
        break;

      case 56: // "rvalue value"
        value.move< std::shared_ptr<ast::RValueValue> > (that.value);
        break;

      case 81: // returnStatement
        value.move< std::shared_ptr<ast::ReturnStatement> > (that.value);
        break;

      case 64: // statement
        value.move< std::shared_ptr<ast::Statement> > (that.value);
        break;

      case 65: // statements
      case 66: // statementsBlockInternal
      case 67: // statementsBlock
        value.move< std::shared_ptr<ast::StatementList> > (that.value);
        break;

      case 82: // valueStandalone
      case 83: // value
        value.move< std::shared_ptr<ast::Value> > (that.value);
        break;

      case 73: // forLoopHeader
      case 87: // functionCallParameters
      case 88: // functionCallParametersMore
        value.move< std::shared_ptr<ast::ValueList> > (that.value);
        break;

      case 70: // localVariableDefinition
      case 80: // functionDefinitionParameter
        value.move< std::shared_ptr<ast::VariableDefinition> > (that.value);
        break;

      case 68: // localVariableDefinitionList
      case 69: // localVariableDefinitions
      case 78: // functionDefinitionParameters
      case 79: // functionDefinitionParametersMore
        value.move< std::shared_ptr<ast::VariableDefinitionList> > (that.value);
        break;

      case 75: // whileLoop
        value.move< std::shared_ptr<ast::WhileLoop> > (that.value);
        break;

      case 53: // "identifier"
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
      case 55: // "loop control statement"
        value.copy< ast::Lexer::ParsedLoopControlStatement > (that.value);
        break;

      case 54: // "variable type"
        value.copy< ast::Lexer::ParsedVariableType > (that.value);
        break;

      case 71: // conditional
      case 72: // conditionalIf
        value.copy< std::shared_ptr<ast::Conditional> > (that.value);
        break;

      case 74: // forLoop
        value.copy< std::shared_ptr<ast::ForLoop> > (that.value);
        break;

      case 86: // functionCall
        value.copy< std::shared_ptr<ast::FunctionCall> > (that.value);
        break;

      case 77: // functionDefinition
        value.copy< std::shared_ptr<ast::FunctionDefinition> > (that.value);
        break;

      case 84: // lValue
        value.copy< std::shared_ptr<ast::LValue> > (that.value);
        break;

      case 76: // loopControlStatement
        value.copy< std::shared_ptr<ast::LoopControlStatement> > (that.value);
        break;

      case 89: // operation
        value.copy< std::shared_ptr<ast::Operation> > (that.value);
        break;

      case 85: // rValue
        value.copy< std::shared_ptr<ast::RValue> > (that.value);
        break;

      case 56: // "rvalue value"
        value.copy< std::shared_ptr<ast::RValueValue> > (that.value);
        break;

      case 81: // returnStatement
        value.copy< std::shared_ptr<ast::ReturnStatement> > (that.value);
        break;

      case 64: // statement
        value.copy< std::shared_ptr<ast::Statement> > (that.value);
        break;

      case 65: // statements
      case 66: // statementsBlockInternal
      case 67: // statementsBlock
        value.copy< std::shared_ptr<ast::StatementList> > (that.value);
        break;

      case 82: // valueStandalone
      case 83: // value
        value.copy< std::shared_ptr<ast::Value> > (that.value);
        break;

      case 73: // forLoopHeader
      case 87: // functionCallParameters
      case 88: // functionCallParametersMore
        value.copy< std::shared_ptr<ast::ValueList> > (that.value);
        break;

      case 70: // localVariableDefinition
      case 80: // functionDefinitionParameter
        value.copy< std::shared_ptr<ast::VariableDefinition> > (that.value);
        break;

      case 68: // localVariableDefinitionList
      case 69: // localVariableDefinitions
      case 78: // functionDefinitionParameters
      case 79: // functionDefinitionParametersMore
        value.copy< std::shared_ptr<ast::VariableDefinitionList> > (that.value);
        break;

      case 75: // whileLoop
        value.copy< std::shared_ptr<ast::WhileLoop> > (that.value);
        break;

      case 53: // "identifier"
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
            case 53: // "identifier"

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::string > ()).name() << " at " << &yysym.value.template as< std::string > (); }
#line 490 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 54: // "variable type"

#line 140 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << ast::Lexer::getString(yysym.value.template as< ast::Lexer::ParsedVariableType > ()); }
#line 497 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 55: // "loop control statement"

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< ast::Lexer::ParsedLoopControlStatement > ()).name() << " at " << &yysym.value.template as< ast::Lexer::ParsedLoopControlStatement > (); }
#line 504 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 56: // "rvalue value"

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::RValueValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::RValueValue> > (); }
#line 511 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 64: // statement

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Statement> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Statement> > (); }
#line 518 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 65: // statements

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 525 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 66: // statementsBlockInternal

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 532 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 67: // statementsBlock

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 539 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 68: // localVariableDefinitionList

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 546 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 69: // localVariableDefinitions

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 553 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 70: // localVariableDefinition

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > (); }
#line 560 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 71: // conditional

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Conditional> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Conditional> > (); }
#line 567 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 72: // conditionalIf

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Conditional> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Conditional> > (); }
#line 574 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 73: // forLoopHeader

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ValueList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ValueList> > (); }
#line 581 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 74: // forLoop

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ForLoop> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ForLoop> > (); }
#line 588 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 75: // whileLoop

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::WhileLoop> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::WhileLoop> > (); }
#line 595 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 76: // loopControlStatement

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::LoopControlStatement> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::LoopControlStatement> > (); }
#line 602 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 77: // functionDefinition

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::FunctionDefinition> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::FunctionDefinition> > (); }
#line 609 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 78: // functionDefinitionParameters

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 616 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 79: // functionDefinitionParametersMore

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 623 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 80: // functionDefinitionParameter

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > (); }
#line 630 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 81: // returnStatement

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ReturnStatement> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ReturnStatement> > (); }
#line 637 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 82: // valueStandalone

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Value> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Value> > (); }
#line 644 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 83: // value

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Value> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Value> > (); }
#line 651 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 84: // lValue

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::LValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::LValue> > (); }
#line 658 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 85: // rValue

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::RValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::RValue> > (); }
#line 665 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 86: // functionCall

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::FunctionCall> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::FunctionCall> > (); }
#line 672 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 87: // functionCallParameters

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ValueList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ValueList> > (); }
#line 679 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 88: // functionCallParametersMore

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ValueList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ValueList> > (); }
#line 686 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 89: // operation

#line 141 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Operation> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Operation> > (); }
#line 693 "gen/scratch-code.tab.cpp" // lalr1.cc:636
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
    #line 44 "src/scratch-code.ypp" // lalr1.cc:741
{
	//initialize the initial location (@$ evaluates to "yyla.location", thus it is not directly associated with my code)
	//"yyla" is in gen/scratch-code.tab.cpp and is a "symbol_type"=instance of "basic_symbol<by_type>" templated class
	//"basic_symbol" class contains member "location" of type "location_type"=instance of "location" class
	//"location" class is in gen/location.hh, has "begin" and "end" members of type "position"
	//"position" class is in gen/position.hh, has "filename" member of type std::string*
	yyla.location.begin.filename = yyla.location.end.filename = driver.getFilenamePointer();
}

#line 816 "gen/scratch-code.tab.cpp" // lalr1.cc:741

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
      case 55: // "loop control statement"
        yylhs.value.build< ast::Lexer::ParsedLoopControlStatement > ();
        break;

      case 54: // "variable type"
        yylhs.value.build< ast::Lexer::ParsedVariableType > ();
        break;

      case 71: // conditional
      case 72: // conditionalIf
        yylhs.value.build< std::shared_ptr<ast::Conditional> > ();
        break;

      case 74: // forLoop
        yylhs.value.build< std::shared_ptr<ast::ForLoop> > ();
        break;

      case 86: // functionCall
        yylhs.value.build< std::shared_ptr<ast::FunctionCall> > ();
        break;

      case 77: // functionDefinition
        yylhs.value.build< std::shared_ptr<ast::FunctionDefinition> > ();
        break;

      case 84: // lValue
        yylhs.value.build< std::shared_ptr<ast::LValue> > ();
        break;

      case 76: // loopControlStatement
        yylhs.value.build< std::shared_ptr<ast::LoopControlStatement> > ();
        break;

      case 89: // operation
        yylhs.value.build< std::shared_ptr<ast::Operation> > ();
        break;

      case 85: // rValue
        yylhs.value.build< std::shared_ptr<ast::RValue> > ();
        break;

      case 56: // "rvalue value"
        yylhs.value.build< std::shared_ptr<ast::RValueValue> > ();
        break;

      case 81: // returnStatement
        yylhs.value.build< std::shared_ptr<ast::ReturnStatement> > ();
        break;

      case 64: // statement
        yylhs.value.build< std::shared_ptr<ast::Statement> > ();
        break;

      case 65: // statements
      case 66: // statementsBlockInternal
      case 67: // statementsBlock
        yylhs.value.build< std::shared_ptr<ast::StatementList> > ();
        break;

      case 82: // valueStandalone
      case 83: // value
        yylhs.value.build< std::shared_ptr<ast::Value> > ();
        break;

      case 73: // forLoopHeader
      case 87: // functionCallParameters
      case 88: // functionCallParametersMore
        yylhs.value.build< std::shared_ptr<ast::ValueList> > ();
        break;

      case 70: // localVariableDefinition
      case 80: // functionDefinitionParameter
        yylhs.value.build< std::shared_ptr<ast::VariableDefinition> > ();
        break;

      case 68: // localVariableDefinitionList
      case 69: // localVariableDefinitions
      case 78: // functionDefinitionParameters
      case 79: // functionDefinitionParametersMore
        yylhs.value.build< std::shared_ptr<ast::VariableDefinitionList> > ();
        break;

      case 75: // whileLoop
        yylhs.value.build< std::shared_ptr<ast::WhileLoop> > ();
        break;

      case 53: // "identifier"
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
#line 165 "src/scratch-code.ypp" // lalr1.cc:859
    {
		*(driver.syntaxTree) = *(yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ());
		
		for(auto stmt : driver.syntaxTree->getStatements())
		{
			//there are only function definitions or variable definitions allowed at the very first level
			if(!stmt->isA<ast::FunctionDefinition>()  &&  !stmt->isA<ast::VariableDefinition>())
				throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations[stmt], "there may only be function or variable definitions at the uppermost level");
		
			//parents of statements on first level need to be assigned manually here (as "unit" expects "statements" and not "statementsBlock")
			stmt->setParent(driver.syntaxTree);
		}
		
		//recFuncs needs to be an lvalue for ast::doRecursively
		//here, basically just function call associations are made
		ast::RecursiveFunctionsType recFuncs =
		{
			{
				//add links to associated functions for all function calls
				ast::FunctionCall::uniqueId,
				[&](std::shared_ptr<ast::Node> obj)
				{
					auto funcCall = std::static_pointer_cast<ast::FunctionCall>(obj);
					
					//search for associated function in all defined functions ("funcCall->getAssocFunc()" is a dummy function here that just contains the function's name)
					std::vector<std::shared_ptr<ast::FunctionDefinition>>::iterator assocFunc = std::find_if(driver.functionDefinitions.begin(), driver.functionDefinitions.end(), [&](auto funcDef) { return (funcDef->getName() == funcCall->getAssocFunc()->getName()); });
					if(assocFunc == driver.functionDefinitions.end())
						throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations[funcCall], "'" + funcCall->getAssocFunc()->getName() + "' was not defined as a function in this scope");
					funcCall->setAssocFunc(*assocFunc);
		
					//check correct types for function call
					auto& assocFuncVarDefs = (*assocFunc)->getArgs()->getVarDefs();
					auto& funcCallArgsValues = funcCall->getArgs()->getValues();
					if(assocFuncVarDefs.size() != funcCallArgsValues.size())
						throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations[funcCall], "wrong number of arguments for function '" + (*assocFunc)->getName() + "' provided, expected " + std::to_string(assocFuncVarDefs.size()) + ", not " + std::to_string(funcCallArgsValues.size()));
					for(auto it = assocFuncVarDefs.begin(); it != assocFuncVarDefs.end(); ++it)
					{
						std::size_t i = std::distance(assocFuncVarDefs.begin(), it);
						ast::Lexer::ParsedVariableType valType = funcCallArgsValues[i]->getEffectiveType();
						if((*it)->getType() != valType)
							throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations[funcCall], "argument " + std::to_string(i+1) + " for function '" + (*assocFunc)->getName() + "' has wrong type, expected '" + ast::Lexer::getString((*it)->getType()) + "', not '" + ast::Lexer::getString(valType) + "'");
					}
				}
			},
			{
				//make sure that no function definition has another function definition as parent
				//also make sure that all function definitions are at the uppermost level (i.e. number of steps to at has to be 1)
				ast::FunctionDefinition::uniqueId,
				[&](std::shared_ptr<ast::Node> obj)
				{
					if(obj->hasParentWithId<ast::FunctionDefinition>())
						throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations.at(obj), "nested function definitions are not allowed");
					
					std::size_t steps;
					if(obj->hasParent<ast::StatementList>(driver.syntaxTree, &steps)  &&  steps > 1)
						throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations.at(obj), "all function definitions need to be at the uppermost level");
				}
			},
			{
				//set target loops for loop control statements
				ast::LoopControlStatement::uniqueId,
				[&](std::shared_ptr<ast::Node> obj)
				{
					auto lcs = std::static_pointer_cast<ast::LoopControlStatement>(obj);
					auto parentLoop = lcs->hasParentWithIdBase<ast::ControllableLoop>();
					if(parentLoop == nullptr)
						throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations.at(lcs), "loop control statement has no loop to target");
					else
					{
						lcs->setTargetLoop(parentLoop);
						driver.nodeLocations.erase(lcs);
					}
				}
			}
		};
		ast::doRecursively(driver.syntaxTree, recFuncs);
		
		//only after the function call associations happened, you can check the correctness of types, as the effective types of function calls were not known previously
		recFuncs =
		{
			{
				//check correct types for binary operation
				ast::BinaryOperation::uniqueId,
				[&](std::shared_ptr<ast::Node> obj)
				{
					auto binOp = std::static_pointer_cast<ast::BinaryOperation>(obj);
				
					//check if types on both sides are the same
					if(binOp->getLhs()->getEffectiveType() != binOp->getRhs()->getEffectiveType())
						throw yy::ScratchCodeParser::syntax_error(yylhs.location, "types for both sides of '" + ast::Lexer::getString(binOp->getOperation()) + "' need to be the same, are currently '" + ast::Lexer::getString(binOp->getLhs()->getEffectiveType()) + "' and '" + ast::Lexer::getString(binOp->getRhs()->getEffectiveType()) + "'");
					
					//check if allowed type for used operation is used (at this point, it's guaranteed that the types of lhs and rhs are the same)
					if(!ast::Lexer::isTypeAllowed(binOp->getOperation(), binOp->getLhs()->getEffectiveType()))
						throw yy::ScratchCodeParser::syntax_error(yylhs.location, "cannot apply '" + ast::Lexer::getString(binOp->getOperation()) + "' to two instances of '" + ast::Lexer::getString(binOp->getLhs()->getEffectiveType()) + "'");
				}
			},
			{
				//check that the if condition evaluates to bool
				ast::Conditional::uniqueId,
				[&](std::shared_ptr<ast::Node> obj)
				{
				
				}
			},
			{
				//check that the for loop condition evaluates to bool
				ast::ForLoop::uniqueId,
				[&](std::shared_ptr<ast::Node> obj)
				{
					auto forLoop = std::static_pointer_cast<ast::ForLoop>(obj);
					ast::Lexer::ParsedVariableType forLoopCondType = (forLoop->getCondition()==nullptr ? ast::Lexer::ParsedVariableType::Bool : forLoop->getCondition()->getEffectiveType());
					if(forLoopCondType != ast::Lexer::ParsedVariableType::Bool)
						throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations.at(forLoop), "for loop condition needs to be of type '" + ast::Lexer::getString(ast::Lexer::ParsedVariableType::Bool) + "', not '" + ast::Lexer::getString(forLoopCondType) + "'");
				}
			},
			{
				//set target functions for return statements and check correct type
				ast::ReturnStatement::uniqueId,
				[&](std::shared_ptr<ast::Node> obj)
				{
					auto retStmt = std::static_pointer_cast<ast::ReturnStatement>(obj);
					auto parentFuncDef = obj->hasParentWithId<ast::FunctionDefinition>();
					if(parentFuncDef == nullptr)
						throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations.at(retStmt), "return statement has no function to target");
					else
					{
						ast::Lexer::ParsedVariableType retStmtValueType = (retStmt->getValue()==nullptr ? ast::Lexer::ParsedVariableType::Void : retStmt->getValue()->getEffectiveType());
						if(parentFuncDef->getReturnType() != retStmtValueType)
							throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations.at(retStmt), "mismatching types for 'return', function '" + parentFuncDef->getName() + "' expects '" + ast::Lexer::getString(parentFuncDef->getReturnType()) + "', not '" + ast::Lexer::getString(retStmtValueType) + "'");
						retStmt->setTargetFunc(parentFuncDef);
						driver.nodeLocations.erase(retStmt);
					}
				}
			},
			{
				//check correct type for unary operations
				ast::UnaryOperation::uniqueId,
				[&](std::shared_ptr<ast::Node> obj)
				{
					auto unOp = std::static_pointer_cast<ast::UnaryOperation>(obj);
					if(!ast::Lexer::isTypeAllowed(unOp->getOperation(), unOp->getValue()->getEffectiveType()))
						throw yy::ScratchCodeParser::syntax_error(yylhs.location, "cannot apply '" + ast::Lexer::getString(unOp->getOperation()) + "' to instance of '" + ast::Lexer::getString(unOp->getValue()->getEffectiveType()) + "'");
				}
			},
			{
				//check that the while loop condition evaluates to bool
				ast::WhileLoop::uniqueId,
				[&](std::shared_ptr<ast::Node> obj)
				{
					auto whileLoop = std::static_pointer_cast<ast::WhileLoop>(obj);
					ast::Lexer::ParsedVariableType whileLoopCondType = whileLoop->getCondition()->getEffectiveType();
					if(whileLoopCondType != ast::Lexer::ParsedVariableType::Bool)
						throw yy::ScratchCodeParser::syntax_error(driver.nodeLocations.at(whileLoop), "while loop condition needs to be of type '" + ast::Lexer::getString(ast::Lexer::ParsedVariableType::Bool) + "', not '" + ast::Lexer::getString(whileLoopCondType) + "'");
				}
			}
		};
		ast::doRecursively(driver.syntaxTree, recFuncs);
		
		//finally optimize the generated syntax tree
		ast::optimize(driver.syntaxTree);
	}
#line 1176 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 330 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::Value> > (); }
#line 1182 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 331 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::Conditional> > (); }
#line 1188 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 332 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::ForLoop> > (); }
#line 1194 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 333 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::WhileLoop> > (); }
#line 1200 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 334 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::LoopControlStatement> > (); }
#line 1206 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 335 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::FunctionDefinition> > (); }
#line 1212 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 336 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::ReturnStatement> > (); }
#line 1218 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 339 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = std::make_shared<ast::StatementList>(nullptr);
	}
#line 1226 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 343 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ()->addStatement(yystack_[0].value.as< std::shared_ptr<ast::Statement> > ());
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 1235 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 348 "src/scratch-code.ypp" // lalr1.cc:859
    {
		for(auto varDef : yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs())
			yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ()->addStatement(varDef);
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 1245 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 355 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 1253 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 359 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newStmtList = std::make_shared<ast::StatementList>(nullptr);
		newStmtList->addStatement(yystack_[0].value.as< std::shared_ptr<ast::Statement> > ());
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = newStmtList;
	}
#line 1263 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 366 "src/scratch-code.ypp" // lalr1.cc:859
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
		
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 1284 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 387 "src/scratch-code.ypp" // lalr1.cc:859
    {
		if(yystack_[3].value.as< ast::Lexer::ParsedVariableType > () == ast::Lexer::ParsedVariableType::Void)
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "variables may not be of type '" + ast::Lexer::getString(yystack_[3].value.as< ast::Lexer::ParsedVariableType > ()) + "'");
	
		yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().insert(yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().begin(), yystack_[2].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		for(auto varDef : yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs())
		{
			varDef->setType(yystack_[3].value.as< ast::Lexer::ParsedVariableType > ());
			driver.variableDefinitions.push_back(varDef);
		}
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1301 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 401 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = std::make_shared<ast::VariableDefinitionList>(nullptr);
	}
#line 1309 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 405 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->addVarDef(yystack_[0].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1318 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 411 "src/scratch-code.ypp" // lalr1.cc:859
    {
		driver.throwIfDefined(yylhs.location, yystack_[0].value.as< std::string > ());
		auto newVarDef = std::make_shared<ast::VariableDefinition>(nullptr, ast::Lexer::ParsedVariableType::Invalid, yystack_[0].value.as< std::string > ());
		driver.nodeLocations[newVarDef] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::VariableDefinition> > () = newVarDef;
	}
#line 1329 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 422 "src/scratch-code.ypp" // lalr1.cc:859
    {
		driver.nodeLocations[yystack_[0].value.as< std::shared_ptr<ast::Conditional> > ()] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = yystack_[0].value.as< std::shared_ptr<ast::Conditional> > ();
	}
#line 1338 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 427 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ());
		yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ()->setAlternativeBody(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		driver.nodeLocations[yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ()] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ();
	}
#line 1349 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 435 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newCond = std::make_shared<ast::Conditional>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), yystack_[0].value.as< std::shared_ptr<ast::StatementList> > (), nullptr);
		yystack_[2].value.as< std::shared_ptr<ast::Value> > ()->setParent(newCond);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newCond);
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = newCond;
	}
#line 1360 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 442 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr, std::vector<std::shared_ptr<ast::Value>>({ yystack_[4].value.as< std::shared_ptr<ast::Value> > (), yystack_[2].value.as< std::shared_ptr<ast::Value> > (), yystack_[0].value.as< std::shared_ptr<ast::Value> > () })); }
#line 1366 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 443 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr, std::vector<std::shared_ptr<ast::Value>>({ yystack_[3].value.as< std::shared_ptr<ast::Value> > (), yystack_[1].value.as< std::shared_ptr<ast::Value> > (), nullptr })); }
#line 1372 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 444 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr, std::vector<std::shared_ptr<ast::Value>>({ nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), yystack_[0].value.as< std::shared_ptr<ast::Value> > () })); }
#line 1378 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 445 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr, std::vector<std::shared_ptr<ast::Value>>({ yystack_[3].value.as< std::shared_ptr<ast::Value> > (), nullptr, yystack_[0].value.as< std::shared_ptr<ast::Value> > () })); }
#line 1384 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 446 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr, std::vector<std::shared_ptr<ast::Value>>({ yystack_[2].value.as< std::shared_ptr<ast::Value> > (), nullptr, nullptr })); }
#line 1390 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 447 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr, std::vector<std::shared_ptr<ast::Value>>({ nullptr, yystack_[1].value.as< std::shared_ptr<ast::Value> > (), nullptr })); }
#line 1396 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 448 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr, std::vector<std::shared_ptr<ast::Value>>({ nullptr, nullptr, yystack_[0].value.as< std::shared_ptr<ast::Value> > () })); }
#line 1402 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 449 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr, std::vector<std::shared_ptr<ast::Value>>({ nullptr, nullptr, nullptr })); }
#line 1408 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 452 "src/scratch-code.ypp" // lalr1.cc:859
    {
		if(yystack_[2].value.as< std::shared_ptr<ast::ValueList> > ()->getValues().size() != 3)
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "fatal inconsistency error");
		auto& header = yystack_[2].value.as< std::shared_ptr<ast::ValueList> > ()->getValues();
		auto newForLoop = std::make_shared<ast::ForLoop>(nullptr, header[0], header[1], header[2], yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		for(auto v : header)
			if(v != nullptr)
				v->setParent(newForLoop);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newForLoop);
		driver.nodeLocations[newForLoop] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::ForLoop> > () = newForLoop;
	}
#line 1425 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 466 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newWhileLoop = std::make_shared<ast::WhileLoop>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yystack_[2].value.as< std::shared_ptr<ast::Value> > ()->setParent(newWhileLoop);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newWhileLoop);
		driver.nodeLocations[newWhileLoop] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::WhileLoop> > () = newWhileLoop;
	}
#line 1437 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 475 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newLCS = std::make_shared<ast::LoopControlStatement>(nullptr, yystack_[1].value.as< ast::Lexer::ParsedLoopControlStatement > (), nullptr);
		driver.nodeLocations[newLCS] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::LoopControlStatement> > () = newLCS;
	}
#line 1447 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 485 "src/scratch-code.ypp" // lalr1.cc:859
    {
		driver.throwIfDefined(yylhs.location, yystack_[4].value.as< std::string > ());
		auto newFuncDef = std::make_shared<ast::FunctionDefinition>(nullptr, yystack_[5].value.as< ast::Lexer::ParsedVariableType > (), yystack_[4].value.as< std::string > (), yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > (), yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->setParent(newFuncDef);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newFuncDef);
		driver.functionDefinitions.push_back(newFuncDef);
		driver.nodeLocations[newFuncDef] = yylhs.location;
		
		//clean up variable definitions of function defintion parameters as the function definition has ended at this point
		for(auto vd : newFuncDef->getArgs()->getVarDefs())															//erase-remove stuff from http://stackoverflow.com/a/3385251
		{
			driver.variableDefinitions.erase(std::remove(driver.variableDefinitions.begin(), driver.variableDefinitions.end(), vd), driver.variableDefinitions.end());
			driver.nodeLocations.erase(vd);
		}
		
		yylhs.value.as< std::shared_ptr<ast::FunctionDefinition> > () = newFuncDef;
	}
#line 1469 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 504 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = std::make_shared<ast::VariableDefinitionList>(nullptr);
	}
#line 1477 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 508 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().insert(yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().begin(), yystack_[1].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1486 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 514 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = std::make_shared<ast::VariableDefinitionList>(nullptr);
	}
#line 1494 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 518 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->addVarDef(yystack_[0].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		yystack_[0].value.as< std::shared_ptr<ast::VariableDefinition> > ()->setParent(yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ());
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1504 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 525 "src/scratch-code.ypp" // lalr1.cc:859
    {
		if(yystack_[1].value.as< ast::Lexer::ParsedVariableType > () == ast::Lexer::ParsedVariableType::Void)
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "function arguments may not be of type '" + ast::Lexer::getString(yystack_[1].value.as< ast::Lexer::ParsedVariableType > ()) + "'");
	
		driver.throwIfDefined(yylhs.location, yystack_[0].value.as< std::string > ());
		auto newVarDef = std::make_shared<ast::VariableDefinition>(nullptr, yystack_[1].value.as< ast::Lexer::ParsedVariableType > (), yystack_[0].value.as< std::string > ());
		driver.variableDefinitions.push_back(newVarDef);
		driver.nodeLocations[newVarDef] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::VariableDefinition> > () = newVarDef;
	}
#line 1519 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 537 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newRetStmt = std::make_shared<ast::ReturnStatement>(nullptr);
		driver.nodeLocations[newRetStmt] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::ReturnStatement> > () = newRetStmt;
	}
#line 1529 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 543 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newRetStmt = std::make_shared<ast::ReturnStatement>(nullptr, yystack_[1].value.as< std::shared_ptr<ast::Value> > (), nullptr);
		yystack_[1].value.as< std::shared_ptr<ast::Value> > ()->setParent(newRetStmt);
		driver.nodeLocations[newRetStmt] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::ReturnStatement> > () = newRetStmt;
	}
#line 1540 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 554 "src/scratch-code.ypp" // lalr1.cc:859
    {
		if(yystack_[1].value.as< std::shared_ptr<ast::Value> > () != nullptr)
			driver.nodeLocations[yystack_[1].value.as< std::shared_ptr<ast::Value> > ()] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[1].value.as< std::shared_ptr<ast::Value> > ();
	}
#line 1550 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 560 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::LValue> > (); }
#line 1556 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 561 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::RValue> > (); }
#line 1562 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 562 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::FunctionCall> > (); }
#line 1568 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 564 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[1].value.as< std::shared_ptr<ast::Value> > ();
	}
#line 1576 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 568 "src/scratch-code.ypp" // lalr1.cc:859
    {
		if(yystack_[0].value.as< std::shared_ptr<ast::Operation> > ()->isA<ast::UnaryOperation>())
		{
			auto unOp = std::static_pointer_cast<ast::UnaryOperation>(yystack_[0].value.as< std::shared_ptr<ast::Operation> > ());
			unOp->getValue()->setParent(unOp);
			
			//check correct value category
			auto valCat = unOp->getValue()->getValueCategory();
			auto reqValCat = unOp->getRequiredValueCategory();
			if(reqValCat != ast::Lexer::ValueCategory::Any  &&  reqValCat != valCat)
				throw yy::ScratchCodeParser::syntax_error(yylhs.location, "unexpected " + ast::Lexer::getString(valCat) + " for value of '" + ast::Lexer::getString(unOp->getOperation()) + "', expecting " + ast::Lexer::getString(reqValCat) + "");
			
			yylhs.value.as< std::shared_ptr<ast::Value> > () = unOp;
		}
		else if(yystack_[0].value.as< std::shared_ptr<ast::Operation> > ()->isA<ast::BinaryOperation>())
		{
			auto binOp = std::static_pointer_cast<ast::BinaryOperation>(yystack_[0].value.as< std::shared_ptr<ast::Operation> > ());
			binOp->getLhs()->setParent(binOp);
			binOp->getRhs()->setParent(binOp);
			
			//check correct value categories for both sides
			auto lhsValCat = binOp->getLhs()->getValueCategory(), rhsValCat = binOp->getRhs()->getValueCategory();
			auto lhsReqValCat = binOp->getRequiredLhsValueCategory(), rhsReqValCat = binOp->getRequiredRhsValueCategory();
			if(lhsReqValCat != ast::Lexer::ValueCategory::Any  &&  lhsReqValCat != lhsValCat)
				throw yy::ScratchCodeParser::syntax_error(yylhs.location, "unexpected " + ast::Lexer::getString(lhsValCat) + " for lhs of '" + ast::Lexer::getString(binOp->getOperation()) + "', expecting '" + ast::Lexer::getString(lhsReqValCat) + "'");
			if(rhsReqValCat != ast::Lexer::ValueCategory::Any  &&  rhsReqValCat != rhsValCat)
				throw yy::ScratchCodeParser::syntax_error(yylhs.location, "unexpected " + ast::Lexer::getString(rhsValCat) + " for rhs of '" + ast::Lexer::getString(binOp->getOperation()) + "', expecting '" + ast::Lexer::getString(rhsReqValCat) + "'");
			
			yylhs.value.as< std::shared_ptr<ast::Value> > () = binOp;
		}
		else
		{
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "fatal inconsistency error");
		}
	}
#line 1616 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 605 "src/scratch-code.ypp" // lalr1.cc:859
    {
		std::vector<std::shared_ptr<ast::VariableDefinition>>::iterator assocVarDef = std::find_if(driver.variableDefinitions.begin(), driver.variableDefinitions.end(), [&](auto varDef) { return (varDef->getName() == yystack_[0].value.as< std::string > ()); });
		if(assocVarDef == driver.variableDefinitions.end())
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "'" + yystack_[0].value.as< std::string > () + "' was not defined as a variable in this scope");
		yylhs.value.as< std::shared_ptr<ast::LValue> > () = std::make_shared<ast::LValue>(nullptr, *assocVarDef);
	}
#line 1627 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 612 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::RValue> > () = yystack_[0].value.as< std::shared_ptr<ast::RValueValue> > (); }
#line 1633 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 618 "src/scratch-code.ypp" // lalr1.cc:859
    {
		//associated function is searched for at the very end to not make function predeclarations necessary
		//also use a dummy function for later that just keeps the function's name
		auto newFuncCall = std::make_shared<ast::FunctionCall>(nullptr, std::make_shared<ast::FunctionDefinition>(nullptr, ast::Lexer::ParsedVariableType::Invalid, yystack_[3].value.as< std::string > (), nullptr, nullptr), yystack_[1].value.as< std::shared_ptr<ast::ValueList> > ());
		yystack_[1].value.as< std::shared_ptr<ast::ValueList> > ()->setParent(newFuncCall);
		driver.nodeLocations[newFuncCall] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::FunctionCall> > () = newFuncCall;
	}
#line 1646 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 628 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr);
	}
#line 1654 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 632 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[0].value.as< std::shared_ptr<ast::ValueList> > ()->getValues().insert(yystack_[0].value.as< std::shared_ptr<ast::ValueList> > ()->getValues().begin(), yystack_[1].value.as< std::shared_ptr<ast::Value> > ());
		yylhs.value.as< std::shared_ptr<ast::ValueList> > () = yystack_[0].value.as< std::shared_ptr<ast::ValueList> > ();
	}
#line 1663 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 638 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr);
	}
#line 1671 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 642 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[2].value.as< std::shared_ptr<ast::ValueList> > ()->addValue(yystack_[0].value.as< std::shared_ptr<ast::Value> > ());
		yystack_[0].value.as< std::shared_ptr<ast::Value> > ()->setParent(yystack_[2].value.as< std::shared_ptr<ast::ValueList> > ());
		yylhs.value.as< std::shared_ptr<ast::ValueList> > () = yystack_[2].value.as< std::shared_ptr<ast::ValueList> > ();
	}
#line 1681 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 651 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Assignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1687 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 652 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::AddAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1693 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 653 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::SubtractAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1699 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 654 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::MultiplyAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1705 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 655 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::DivideAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1711 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 656 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::ModuloAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1717 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 657 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseAndAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1723 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 658 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseOrAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1729 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 659 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseXorAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1735 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 660 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftLeftAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1741 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 661 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftRightAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1747 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 662 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LogicalOr, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1753 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 663 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LogicalAnd, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1759 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 664 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseOr, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1765 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 665 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseXor, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1771 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 666 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseAnd, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1777 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 667 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Equal, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1783 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 668 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::NotEqual, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1789 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 669 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LessThan, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1795 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 670 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LessThanOrEqual, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1801 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 671 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::GreaterThan, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1807 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 672 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::GreaterThanOrEqual, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1813 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 673 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftLeft, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1819 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 674 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftRight, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1825 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 675 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Add, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1831 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 676 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Subtract, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1837 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 677 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Multiply, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1843 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 678 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Divide, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1849 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 679 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Modulo, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1855 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 680 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PrefixIncrement, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1861 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 681 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PrefixDecrement, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1867 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 682 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::UnaryPlus, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1873 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 683 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::UnaryMinus, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1879 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 684 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::LogicalNot, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1885 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 685 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::BitwiseNot, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1891 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 686 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::TypecastBool, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1897 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 687 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::TypecastInt, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1903 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 688 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::TypecastReal, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1909 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 689 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::TypecastString, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1915 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 690 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PostfixIncrement, yystack_[1].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1921 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 691 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PostfixDecrement, yystack_[1].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1927 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;


#line 1931 "gen/scratch-code.tab.cpp" // lalr1.cc:859
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


  const signed char ScratchCodeParser::yypact_ninf_ = -116;

  const signed char ScratchCodeParser::yytable_ninf_ = -1;

  const short int
  ScratchCodeParser::yypact_[] =
  {
    -116,    12,    84,  -116,  -116,     8,     9,    19,   189,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
      28,   -16,    29,  -116,  -116,  -116,  -116,    41,  -116,  -116,
    -116,  -116,  -116,  -116,   429,  -116,  -116,  -116,  -116,   272,
     272,   212,  -116,   467,   303,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,   272,    40,  -116,  -116,   147,
    -116,   272,   272,  -116,  -116,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   347,   391,   231,    42,   505,  -116,  -116,   618,
      43,    -5,    10,  -116,    -3,  -116,  -116,  -116,    97,    97,
      -4,    -4,    -4,     2,   707,   733,   287,   287,   681,   655,
      94,    94,    94,    94,   759,   759,   618,   618,   618,   618,
     618,   618,   618,   618,   618,   618,   618,   147,   147,   272,
     543,   147,   254,    71,  -116,     3,    46,  -116,    35,  -116,
     170,    40,  -116,  -116,   618,   272,  -116,   272,   581,   272,
    -116,   147,    79,  -116,  -116,  -116,   618,   618,   272,   618,
    -116,    -5,   618,  -116
  };

  const unsigned char
  ScratchCodeParser::yydefact_[] =
  {
      10,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,    49,    11,    12,     4,    20,     5,     6,
       7,     8,     9,     3,     0,    43,    44,    45,    47,     0,
       0,     0,    40,     0,     0,    86,    87,    84,    85,    88,
      89,    90,    91,    92,    93,    51,    19,    17,    33,     0,
      42,     0,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    46,    53,
       0,    35,     0,    10,     0,    14,    15,    21,    79,    80,
      81,    82,    83,    70,    68,    69,    77,    78,    67,    66,
      73,    74,    75,    76,    71,    72,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,    30,
       0,     0,     0,    52,    50,     0,     0,    37,     0,    16,
       0,     0,    22,    32,    29,    28,    31,    27,     0,     0,
      39,     0,    36,    19,    18,    13,    25,    26,    24,    54,
      34,     0,    23,    38
  };

  const signed char
  ScratchCodeParser::yypgoto_[] =
  {
    -116,  -116,    11,    -9,  -116,  -115,  -116,  -116,   -53,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   -75,  -116,
    -116,    -8,  -116,  -116,  -116,  -116,  -116,  -116
  };

  const short int
  ScratchCodeParser::yydefgoto_[] =
  {
      -1,     1,   105,     2,   106,   107,    25,   102,    57,    26,
      27,    95,    28,    29,    30,    31,   146,   162,   147,    32,
      33,    34,    35,    36,    37,   100,   143,    38
  };

  const unsigned char
  ScratchCodeParser::yytable_[] =
  {
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     3,    24,    63,    64,    39,    40,    61,    62,
      63,    64,   152,   153,   148,   149,   156,    41,    65,    66,
      67,    92,    93,    96,    71,    72,    55,    56,    75,    76,
      77,    78,    79,    80,    58,    59,   170,    99,   101,   145,
     151,   141,   144,   108,   109,   161,   160,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     4,   159,   140,     5,   163,     6,
       7,     8,     9,   171,   150,   164,   173,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      61,    62,    63,    64,     0,    63,    64,     0,     0,     0,
      65,    66,    67,    65,    66,    67,    71,    72,     0,     0,
       0,   154,     0,     0,   158,     0,     0,    20,    21,    22,
      23,     0,     0,     0,     0,     0,     0,   166,     0,   167,
       5,   169,     6,     7,     8,     9,     0,     0,     0,   103,
     172,    24,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     5,     0,     6,     7,     8,     9,     0,
       0,     0,     0,   165,     0,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,     9,     0,     0,
      20,   104,    22,    23,    42,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       9,     0,     0,    20,    21,    22,    23,    94,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     9,
       0,     0,    20,     0,     0,    23,   139,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,     9,     0,     0,    20,     0,     0,    23,   157,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       9,     0,     0,     0,    20,     0,     0,    23,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    61,    62,    63,    64,    20,     0,     0,
      23,     0,    98,    65,    66,    67,     0,     0,     0,    61,
      62,    63,    64,     0,     0,    20,     0,     0,    23,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   137,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     138,     0,     0,     0,     0,     0,     0,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    97,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     142,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   155,    61,
      62,    63,    64,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   168,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    75,    76,    77,
      78,    79,    80,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,     0,    70,    71,
      72,     0,     0,    75,    76,    77,    78,    79,    80,    61,
      62,    63,    64,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,     0,     0,    71,    72,     0,     0,    75,
      76,    77,    78,    79,    80,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,    65,    66,    67,     0,     0,
       0,    71,    72,     0,     0,    75,    76,    77,    78
  };

  const short int
  ScratchCodeParser::yycheck_[] =
  {
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     2,    18,    19,     8,     8,    16,    17,
      18,    19,   137,   138,    14,    15,   141,     8,    26,    27,
      28,    39,    40,    41,    32,    33,     8,    53,    36,    37,
      38,    39,    40,    41,    15,     4,   161,    55,     8,    54,
      53,     9,     9,    61,    62,     9,    53,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    14,    94,     3,    53,     5,
       6,     7,     8,    14,   103,   148,   171,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      16,    17,    18,    19,    -1,    18,    19,    -1,    -1,    -1,
      26,    27,    28,    26,    27,    28,    32,    33,    -1,    -1,
      -1,   139,    -1,    -1,   142,    -1,    -1,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,
       3,   159,     5,     6,     7,     8,    -1,    -1,    -1,    12,
     168,   150,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     3,    -1,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,     8,    -1,    -1,
      53,    54,    55,    56,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    53,    54,    55,    56,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,     8,
      -1,    -1,    53,    -1,    -1,    56,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    53,    -1,    -1,    56,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       8,    -1,    -1,    -1,    53,    -1,    -1,    56,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    53,    -1,    -1,
      56,    -1,     9,    26,    27,    28,    -1,    -1,    -1,    16,
      17,    18,    19,    -1,    -1,    53,    -1,    -1,    56,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    40,    41,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    -1,    36,    37,    38,    39,    40,    41,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,
      -1,    32,    33,    -1,    -1,    36,    37,    38,    39
  };

  const unsigned char
  ScratchCodeParser::yystos_[] =
  {
       0,    63,    65,     0,     0,     3,     5,     6,     7,     8,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      53,    54,    55,    56,    64,    68,    71,    72,    74,    75,
      76,    77,    81,    82,    83,    84,    85,    86,    89,     8,
       8,     8,    15,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,     8,    53,    70,    15,     4,
      15,    16,    17,    18,    19,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    83,    83,    15,    73,    83,    15,     9,    83,
      87,     8,    69,    12,    54,    64,    66,    67,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,     9,     9,    15,
      83,     9,    15,    88,     9,    54,    78,    80,    14,    15,
      65,    53,    67,    67,    83,    15,    67,    15,    83,    14,
      53,     9,    79,    53,    70,    13,    83,    83,    15,    83,
      67,    14,    83,    80
  };

  const unsigned char
  ScratchCodeParser::yyr1_[] =
  {
       0,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      71,    71,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    75,    76,    77,    78,    78,    79,    79,    80,
      81,    81,    82,    83,    83,    83,    83,    83,    84,    85,
      86,    87,    87,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89
  };

  const unsigned char
  ScratchCodeParser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     2,     3,     1,     1,     4,     0,     3,     1,
       1,     3,     5,     5,     4,     4,     4,     3,     3,     3,
       2,     5,     5,     2,     6,     0,     2,     0,     3,     2,
       2,     3,     2,     1,     1,     1,     3,     1,     1,     1,
       4,     0,     2,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const ScratchCodeParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"if\"", "\"else\"",
  "\"while\"", "\"for\"", "\"return\"", "\"(\"", "\")\"", "\"[\"", "\"]\"",
  "\"{\"", "\"}\"", "\",\"", "\";\"", "\"+\"", "\"-\"", "\"++\"", "\"--\"",
  "\"!\"", "\"~\"", "\"(bool)\"", "\"(int)\"", "\"(real)\"",
  "\"(string)\"", "\"*\"", "\"/\"", "\"%\"", "\"&\"", "\"|\"", "\"^\"",
  "\"<<\"", "\">>\"", "\"&&\"", "\"||\"", "\"<\"", "\"<=\"", "\">\"",
  "\">=\"", "\"==\"", "\"!=\"", "\"=\"", "\"+=\"", "\"-=\"", "\"*=\"",
  "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"", "\"^=\"", "\"<<=\"", "\">>=\"",
  "\"identifier\"", "\"variable type\"", "\"loop control statement\"",
  "\"rvalue value\"", "\"then\"", "UNOP_UNARY_PLUS", "UNOP_UNARY_MINUS",
  "UNOP_POSTFIX_INCREMENT", "UNOP_POSTFIX_DECREMENT", "$accept", "unit",
  "statement", "statements", "statementsBlockInternal", "statementsBlock",
  "localVariableDefinitionList", "localVariableDefinitions",
  "localVariableDefinition", "conditional", "conditionalIf",
  "forLoopHeader", "forLoop", "whileLoop", "loopControlStatement",
  "functionDefinition", "functionDefinitionParameters",
  "functionDefinitionParametersMore", "functionDefinitionParameter",
  "returnStatement", "valueStandalone", "value", "lValue", "rValue",
  "functionCall", "functionCallParameters", "functionCallParametersMore",
  "operation", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  ScratchCodeParser::yyrline_[] =
  {
       0,   164,   164,   330,   331,   332,   333,   334,   335,   336,
     338,   342,   347,   354,   358,   365,   386,   400,   404,   410,
     421,   426,   434,   442,   443,   444,   445,   446,   447,   448,
     449,   451,   465,   474,   484,   503,   507,   513,   517,   524,
     536,   542,   553,   560,   561,   562,   563,   567,   604,   612,
     617,   627,   631,   637,   641,   651,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691
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
#line 2552 "gen/scratch-code.tab.cpp" // lalr1.cc:1167
#line 692 "src/scratch-code.ypp" // lalr1.cc:1168




#include "Main.hpp"

void yy::ScratchCodeParser::error(const yy::location& loc, const std::string& message)
{
	driver.handleError(loc, message);
}

