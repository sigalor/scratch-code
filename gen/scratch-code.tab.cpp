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
#line 36 "src/scratch-code.ypp" // lalr1.cc:413

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

      case 73: // forLoop
        value.move< std::shared_ptr<ast::ForLoop> > (that.value);
        break;

      case 85: // functionCall
        value.move< std::shared_ptr<ast::FunctionCall> > (that.value);
        break;

      case 76: // functionDefinition
        value.move< std::shared_ptr<ast::FunctionDefinition> > (that.value);
        break;

      case 83: // lValue
        value.move< std::shared_ptr<ast::LValue> > (that.value);
        break;

      case 75: // loopControlStatement
        value.move< std::shared_ptr<ast::LoopControlStatement> > (that.value);
        break;

      case 88: // operation
        value.move< std::shared_ptr<ast::Operation> > (that.value);
        break;

      case 84: // rValue
        value.move< std::shared_ptr<ast::RValue> > (that.value);
        break;

      case 56: // "rvalue value"
        value.move< std::shared_ptr<ast::RValueValue> > (that.value);
        break;

      case 80: // returnStatement
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

      case 81: // valueStandalone
      case 82: // value
        value.move< std::shared_ptr<ast::Value> > (that.value);
        break;

      case 86: // functionCallParameters
      case 87: // functionCallParametersMore
        value.move< std::shared_ptr<ast::ValueList> > (that.value);
        break;

      case 70: // localVariableDefinition
      case 79: // functionDefinitionParameter
        value.move< std::shared_ptr<ast::VariableDefinition> > (that.value);
        break;

      case 68: // localVariableDefinitionList
      case 69: // localVariableDefinitions
      case 77: // functionDefinitionParameters
      case 78: // functionDefinitionParametersMore
        value.move< std::shared_ptr<ast::VariableDefinitionList> > (that.value);
        break;

      case 74: // whileLoop
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

      case 73: // forLoop
        value.copy< std::shared_ptr<ast::ForLoop> > (that.value);
        break;

      case 85: // functionCall
        value.copy< std::shared_ptr<ast::FunctionCall> > (that.value);
        break;

      case 76: // functionDefinition
        value.copy< std::shared_ptr<ast::FunctionDefinition> > (that.value);
        break;

      case 83: // lValue
        value.copy< std::shared_ptr<ast::LValue> > (that.value);
        break;

      case 75: // loopControlStatement
        value.copy< std::shared_ptr<ast::LoopControlStatement> > (that.value);
        break;

      case 88: // operation
        value.copy< std::shared_ptr<ast::Operation> > (that.value);
        break;

      case 84: // rValue
        value.copy< std::shared_ptr<ast::RValue> > (that.value);
        break;

      case 56: // "rvalue value"
        value.copy< std::shared_ptr<ast::RValueValue> > (that.value);
        break;

      case 80: // returnStatement
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

      case 81: // valueStandalone
      case 82: // value
        value.copy< std::shared_ptr<ast::Value> > (that.value);
        break;

      case 86: // functionCallParameters
      case 87: // functionCallParametersMore
        value.copy< std::shared_ptr<ast::ValueList> > (that.value);
        break;

      case 70: // localVariableDefinition
      case 79: // functionDefinitionParameter
        value.copy< std::shared_ptr<ast::VariableDefinition> > (that.value);
        break;

      case 68: // localVariableDefinitionList
      case 69: // localVariableDefinitions
      case 77: // functionDefinitionParameters
      case 78: // functionDefinitionParametersMore
        value.copy< std::shared_ptr<ast::VariableDefinitionList> > (that.value);
        break;

      case 74: // whileLoop
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

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::string > ()).name() << " at " << &yysym.value.template as< std::string > (); }
#line 488 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 54: // "variable type"

#line 119 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << ast::Lexer::getString(yysym.value.template as< ast::Lexer::ParsedVariableType > ()); }
#line 495 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 55: // "loop control statement"

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< ast::Lexer::ParsedLoopControlStatement > ()).name() << " at " << &yysym.value.template as< ast::Lexer::ParsedLoopControlStatement > (); }
#line 502 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 56: // "rvalue value"

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::RValueValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::RValueValue> > (); }
#line 509 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 64: // statement

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Statement> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Statement> > (); }
#line 516 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 65: // statements

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 523 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 66: // statementsBlockInternal

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 530 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 67: // statementsBlock

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 537 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 68: // localVariableDefinitionList

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 544 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 69: // localVariableDefinitions

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 551 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 70: // localVariableDefinition

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > (); }
#line 558 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 71: // conditional

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Conditional> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Conditional> > (); }
#line 565 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 72: // conditionalIf

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Conditional> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Conditional> > (); }
#line 572 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 73: // forLoop

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ForLoop> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ForLoop> > (); }
#line 579 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 74: // whileLoop

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::WhileLoop> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::WhileLoop> > (); }
#line 586 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 75: // loopControlStatement

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::LoopControlStatement> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::LoopControlStatement> > (); }
#line 593 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 76: // functionDefinition

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::FunctionDefinition> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::FunctionDefinition> > (); }
#line 600 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 77: // functionDefinitionParameters

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 607 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 78: // functionDefinitionParametersMore

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 614 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 79: // functionDefinitionParameter

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > (); }
#line 621 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 80: // returnStatement

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ReturnStatement> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ReturnStatement> > (); }
#line 628 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 81: // valueStandalone

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Value> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Value> > (); }
#line 635 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 82: // value

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Value> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Value> > (); }
#line 642 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 83: // lValue

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::LValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::LValue> > (); }
#line 649 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 84: // rValue

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::RValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::RValue> > (); }
#line 656 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 85: // functionCall

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::FunctionCall> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::FunctionCall> > (); }
#line 663 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 86: // functionCallParameters

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ValueList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ValueList> > (); }
#line 670 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 87: // functionCallParametersMore

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::ValueList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::ValueList> > (); }
#line 677 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 88: // operation

#line 120 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Operation> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Operation> > (); }
#line 684 "gen/scratch-code.tab.cpp" // lalr1.cc:636
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
    #line 24 "src/scratch-code.ypp" // lalr1.cc:741
{
	//initialize the initial location (@$ evaluates to "yyla.location", thus it is not directly associated with my code)
	//"yyla" is in gen/scratch-code.tab.cpp and is a "symbol_type"=instance of "basic_symbol<by_type>" templated class
	//"basic_symbol" class contains member "location" of type "location_type"=instance of "location" class
	//"location" class is in gen/location.hh, has "begin" and "end" members of type "position"
	//"position" class is in gen/position.hh, has "filename" member of type std::string*
	yyla.location.begin.filename = yyla.location.end.filename = driver.getFilenamePointer();
}

#line 807 "gen/scratch-code.tab.cpp" // lalr1.cc:741

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

      case 73: // forLoop
        yylhs.value.build< std::shared_ptr<ast::ForLoop> > ();
        break;

      case 85: // functionCall
        yylhs.value.build< std::shared_ptr<ast::FunctionCall> > ();
        break;

      case 76: // functionDefinition
        yylhs.value.build< std::shared_ptr<ast::FunctionDefinition> > ();
        break;

      case 83: // lValue
        yylhs.value.build< std::shared_ptr<ast::LValue> > ();
        break;

      case 75: // loopControlStatement
        yylhs.value.build< std::shared_ptr<ast::LoopControlStatement> > ();
        break;

      case 88: // operation
        yylhs.value.build< std::shared_ptr<ast::Operation> > ();
        break;

      case 84: // rValue
        yylhs.value.build< std::shared_ptr<ast::RValue> > ();
        break;

      case 56: // "rvalue value"
        yylhs.value.build< std::shared_ptr<ast::RValueValue> > ();
        break;

      case 80: // returnStatement
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

      case 81: // valueStandalone
      case 82: // value
        yylhs.value.build< std::shared_ptr<ast::Value> > ();
        break;

      case 86: // functionCallParameters
      case 87: // functionCallParametersMore
        yylhs.value.build< std::shared_ptr<ast::ValueList> > ();
        break;

      case 70: // localVariableDefinition
      case 79: // functionDefinitionParameter
        yylhs.value.build< std::shared_ptr<ast::VariableDefinition> > ();
        break;

      case 68: // localVariableDefinitionList
      case 69: // localVariableDefinitions
      case 77: // functionDefinitionParameters
      case 78: // functionDefinitionParametersMore
        yylhs.value.build< std::shared_ptr<ast::VariableDefinitionList> > ();
        break;

      case 74: // whileLoop
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
#line 144 "src/scratch-code.ypp" // lalr1.cc:859
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
			}
		};
		ast::doRecursively(driver.syntaxTree, recFuncs);
	}
#line 1133 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 276 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::Value> > (); }
#line 1139 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 277 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::Conditional> > (); }
#line 1145 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 278 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::ForLoop> > (); }
#line 1151 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 279 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::WhileLoop> > (); }
#line 1157 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 280 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::LoopControlStatement> > (); }
#line 1163 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 281 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::FunctionDefinition> > (); }
#line 1169 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 282 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::ReturnStatement> > (); }
#line 1175 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 285 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = std::make_shared<ast::StatementList>(nullptr);
	}
#line 1183 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 289 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ()->addStatement(yystack_[0].value.as< std::shared_ptr<ast::Statement> > ());
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 1192 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 294 "src/scratch-code.ypp" // lalr1.cc:859
    {
		for(auto varDef : yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs())
			yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ()->addStatement(varDef);
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 1202 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 301 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 1210 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 305 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newStmtList = std::make_shared<ast::StatementList>(nullptr);
		newStmtList->addStatement(yystack_[0].value.as< std::shared_ptr<ast::Statement> > ());
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = newStmtList;
	}
#line 1220 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 312 "src/scratch-code.ypp" // lalr1.cc:859
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
#line 1241 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 333 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().insert(yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().begin(), yystack_[2].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		for(auto varDef : yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs())
		{
			varDef->setType(yystack_[3].value.as< ast::Lexer::ParsedVariableType > ());
			driver.variableDefinitions.push_back(varDef);
		}
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1255 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 344 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = std::make_shared<ast::VariableDefinitionList>(nullptr);
	}
#line 1263 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 348 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->addVarDef(yystack_[0].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1272 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 354 "src/scratch-code.ypp" // lalr1.cc:859
    {
		driver.throwIfDefined(yylhs.location, yystack_[0].value.as< std::string > ());
		auto newVarDef = std::make_shared<ast::VariableDefinition>(nullptr, ast::Lexer::ParsedVariableType::Invalid, yystack_[0].value.as< std::string > ());
		driver.nodeLocations[newVarDef] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::VariableDefinition> > () = newVarDef;
	}
#line 1283 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 365 "src/scratch-code.ypp" // lalr1.cc:859
    {
		driver.nodeLocations[yystack_[0].value.as< std::shared_ptr<ast::Conditional> > ()] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = yystack_[0].value.as< std::shared_ptr<ast::Conditional> > ();
	}
#line 1292 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 370 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ());
		yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ()->setAlternativeBody(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		driver.nodeLocations[yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ()] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ();
	}
#line 1303 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 378 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newCond = std::make_shared<ast::Conditional>(nullptr);
		yystack_[2].value.as< std::shared_ptr<ast::Value> > ()->setParent(newCond);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newCond);
		newCond->addCondition(yystack_[2].value.as< std::shared_ptr<ast::Value> > ());
		newCond->addConsequenceBody(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = newCond;
	}
#line 1316 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 388 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newForLoop = std::make_shared<ast::ForLoop>(nullptr, yystack_[6].value.as< std::shared_ptr<ast::Value> > (), yystack_[4].value.as< std::shared_ptr<ast::Value> > (), yystack_[2].value.as< std::shared_ptr<ast::Value> > (), yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yystack_[6].value.as< std::shared_ptr<ast::Value> > ()->setParent(newForLoop);
		yystack_[4].value.as< std::shared_ptr<ast::Value> > ()->setParent(newForLoop);
		yystack_[2].value.as< std::shared_ptr<ast::Value> > ()->setParent(newForLoop);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newForLoop);
		driver.nodeLocations[newForLoop] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::ForLoop> > () = newForLoop;
	}
#line 1330 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 399 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newWhileLoop = std::make_shared<ast::WhileLoop>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yystack_[2].value.as< std::shared_ptr<ast::Value> > ()->setParent(newWhileLoop);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newWhileLoop);
		driver.nodeLocations[newWhileLoop] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::WhileLoop> > () = newWhileLoop;
	}
#line 1342 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 408 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newLCS = std::make_shared<ast::LoopControlStatement>(nullptr, yystack_[1].value.as< ast::Lexer::ParsedLoopControlStatement > (), nullptr);
		driver.nodeLocations[newLCS] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::LoopControlStatement> > () = newLCS;
	}
#line 1352 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 418 "src/scratch-code.ypp" // lalr1.cc:859
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
#line 1374 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 437 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = std::make_shared<ast::VariableDefinitionList>(nullptr);
	}
#line 1382 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 441 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().insert(yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().begin(), yystack_[1].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1391 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 447 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = std::make_shared<ast::VariableDefinitionList>(nullptr);
	}
#line 1399 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 451 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->addVarDef(yystack_[0].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		yystack_[0].value.as< std::shared_ptr<ast::VariableDefinition> > ()->setParent(yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ());
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 1409 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 458 "src/scratch-code.ypp" // lalr1.cc:859
    {
		driver.throwIfDefined(yylhs.location, yystack_[0].value.as< std::string > ());
		auto newVarDef = std::make_shared<ast::VariableDefinition>(nullptr, yystack_[1].value.as< ast::Lexer::ParsedVariableType > (), yystack_[0].value.as< std::string > ());
		driver.variableDefinitions.push_back(newVarDef);
		driver.nodeLocations[newVarDef] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::VariableDefinition> > () = newVarDef;
	}
#line 1421 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 467 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newRetStmt = std::make_shared<ast::ReturnStatement>(nullptr);
		driver.nodeLocations[newRetStmt] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::ReturnStatement> > () = newRetStmt;
	}
#line 1431 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 473 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newRetStmt = std::make_shared<ast::ReturnStatement>(nullptr, yystack_[1].value.as< std::shared_ptr<ast::Value> > (), nullptr);
		yystack_[1].value.as< std::shared_ptr<ast::Value> > ()->setParent(newRetStmt);
		driver.nodeLocations[newRetStmt] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::ReturnStatement> > () = newRetStmt;
	}
#line 1442 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 484 "src/scratch-code.ypp" // lalr1.cc:859
    {
		driver.nodeLocations[yystack_[1].value.as< std::shared_ptr<ast::Value> > ()] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[1].value.as< std::shared_ptr<ast::Value> > ();
	}
#line 1451 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 489 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::LValue> > (); }
#line 1457 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 490 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::RValue> > (); }
#line 1463 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 491 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::FunctionCall> > (); }
#line 1469 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 493 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[1].value.as< std::shared_ptr<ast::Value> > ();
	}
#line 1477 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 497 "src/scratch-code.ypp" // lalr1.cc:859
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
#line 1517 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 534 "src/scratch-code.ypp" // lalr1.cc:859
    {
		std::vector<std::shared_ptr<ast::VariableDefinition>>::iterator assocVarDef = std::find_if(driver.variableDefinitions.begin(), driver.variableDefinitions.end(), [&](auto varDef) { return (varDef->getName() == yystack_[0].value.as< std::string > ()); });
		if(assocVarDef == driver.variableDefinitions.end())
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "'" + yystack_[0].value.as< std::string > () + "' was not defined as a variable in this scope");
		yylhs.value.as< std::shared_ptr<ast::LValue> > () = std::make_shared<ast::LValue>(nullptr, *assocVarDef);
	}
#line 1528 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 541 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::RValue> > () = yystack_[0].value.as< std::shared_ptr<ast::RValueValue> > (); }
#line 1534 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 547 "src/scratch-code.ypp" // lalr1.cc:859
    {
		//associated function is searched for at the very end to not make function predeclarations necessary
		//also use a dummy function for later that just keeps the function's name
		auto newFuncCall = std::make_shared<ast::FunctionCall>(nullptr, std::make_shared<ast::FunctionDefinition>(nullptr, ast::Lexer::ParsedVariableType::Invalid, yystack_[3].value.as< std::string > (), nullptr, nullptr), yystack_[1].value.as< std::shared_ptr<ast::ValueList> > ());
		yystack_[1].value.as< std::shared_ptr<ast::ValueList> > ()->setParent(newFuncCall);
		driver.nodeLocations[newFuncCall] = yylhs.location;
		yylhs.value.as< std::shared_ptr<ast::FunctionCall> > () = newFuncCall;
	}
#line 1547 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 557 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr);
	}
#line 1555 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 561 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[0].value.as< std::shared_ptr<ast::ValueList> > ()->getValues().insert(yystack_[0].value.as< std::shared_ptr<ast::ValueList> > ()->getValues().begin(), yystack_[1].value.as< std::shared_ptr<ast::Value> > ());
		yylhs.value.as< std::shared_ptr<ast::ValueList> > () = yystack_[0].value.as< std::shared_ptr<ast::ValueList> > ();
	}
#line 1564 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 567 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::ValueList> > () = std::make_shared<ast::ValueList>(nullptr);
	}
#line 1572 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 571 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[2].value.as< std::shared_ptr<ast::ValueList> > ()->addValue(yystack_[0].value.as< std::shared_ptr<ast::Value> > ());
		yystack_[0].value.as< std::shared_ptr<ast::Value> > ()->setParent(yystack_[2].value.as< std::shared_ptr<ast::ValueList> > ());
		yylhs.value.as< std::shared_ptr<ast::ValueList> > () = yystack_[2].value.as< std::shared_ptr<ast::ValueList> > ();
	}
#line 1582 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 580 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Assignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1588 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 581 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::AddAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1594 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 582 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::SubtractAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1600 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 583 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::MultiplyAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1606 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 584 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::DivideAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1612 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 585 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::ModuloAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1618 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 586 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseAndAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1624 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 587 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseOrAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1630 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 588 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseXorAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1636 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 589 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftLeftAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1642 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 590 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftRightAssignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1648 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 591 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LogicalOr, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1654 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 592 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LogicalAnd, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1660 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 593 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseOr, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1666 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 594 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseXor, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1672 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 595 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitwiseAnd, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1678 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 596 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Equal, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1684 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 597 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::NotEqual, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1690 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 598 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LessThan, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1696 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 599 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::LessThanOrEqual, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1702 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 600 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::GreaterThan, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1708 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 601 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::GreaterThanOrEqual, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1714 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 602 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftLeft, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1720 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 603 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::BitshiftRight, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1726 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 604 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Add, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1732 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 605 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Subtract, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1738 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 606 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Multiply, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1744 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 607 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Divide, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1750 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 608 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Modulo, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1756 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 609 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PrefixIncrement, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1762 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 610 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PrefixDecrement, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1768 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 611 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::UnaryPlus, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1774 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 612 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::UnaryMinus, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1780 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 613 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::LogicalNot, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1786 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 614 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::BitwiseNot, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1792 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 615 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::TypecastBool, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1798 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 616 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::TypecastInt, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1804 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 617 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::TypecastReal, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1810 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 618 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::TypecastString, yystack_[0].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1816 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 619 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PostfixIncrement, yystack_[1].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1822 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 620 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Operation> > () = std::make_shared<ast::UnaryOperation>(nullptr, ast::Lexer::ParsedUnaryOperation::PostfixDecrement, yystack_[1].value.as< std::shared_ptr<ast::Value> > ()); }
#line 1828 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;


#line 1832 "gen/scratch-code.tab.cpp" // lalr1.cc:859
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


  const signed char ScratchCodeParser::yypact_ninf_ = -123;

  const signed char ScratchCodeParser::yytable_ninf_ = -1;

  const short int
  ScratchCodeParser::yypact_[] =
  {
    -123,    23,    84,  -123,  -123,    16,    20,    21,   182,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
      30,   -14,    25,  -123,  -123,  -123,  -123,    38,  -123,  -123,
    -123,  -123,  -123,  -123,   405,  -123,  -123,  -123,  -123,   204,
     204,   204,  -123,   443,   235,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,   204,    35,  -123,  -123,   140,
    -123,   204,   204,  -123,  -123,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   279,   323,   481,  -123,  -123,   556,    39,    -5,
       7,  -123,     2,  -123,  -123,  -123,    67,    67,     1,     1,
       1,   671,   619,   645,    -1,    -1,   593,    94,    18,    18,
      18,    18,   697,   697,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   140,   140,   204,    42,  -123,
      43,    79,  -123,    44,  -123,   163,    35,  -123,  -123,   519,
     204,  -123,   140,    85,  -123,  -123,  -123,   204,   556,  -123,
      -5,   367,  -123,   140,  -123
  };

  const unsigned char
  ScratchCodeParser::yydefact_[] =
  {
      10,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,     0,     0,    41,    11,    12,     4,    20,     5,     6,
       7,     8,     9,     3,     0,    35,    36,    37,    39,     0,
       0,     0,    32,     0,     0,    78,    79,    76,    77,    80,
      81,    82,    83,    84,    85,    43,    19,    17,    25,     0,
      34,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    38,    45,     0,    27,
       0,    10,     0,    14,    15,    21,    71,    72,    73,    74,
      75,    62,    60,    61,    69,    70,    59,    58,    65,    66,
      67,    68,    63,    64,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    44,    42,
       0,     0,    29,     0,    16,     0,     0,    22,    24,     0,
       0,    31,     0,    28,    19,    18,    13,     0,    46,    26,
       0,     0,    30,     0,    23
  };

  const signed char
  ScratchCodeParser::yypgoto_[] =
  {
    -123,  -123,    10,   -49,  -123,  -122,  -123,  -123,   -45,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,   -46,  -123,  -123,
      -8,  -123,  -123,  -123,  -123,  -123,  -123
  };

  const short int
  ScratchCodeParser::yydefgoto_[] =
  {
      -1,     1,   103,     2,   104,   105,    25,   100,    57,    26,
      27,    28,    29,    30,    31,   141,   153,   142,    32,    33,
      34,    35,    36,    37,    98,   138,    38
  };

  const unsigned char
  ScratchCodeParser::yytable_[] =
  {
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    24,   147,   148,    61,    62,    63,    64,    63,
      64,   143,   144,     3,    39,    65,    66,    67,    40,    41,
     159,    92,    93,    94,    61,    62,    63,    64,    55,    56,
      58,   164,    59,    99,    65,    66,    67,    97,   139,   140,
      71,    72,   145,   106,   107,   146,   150,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,     4,    63,    64,     5,   152,     6,
       7,     8,     9,    65,    66,    67,   151,   154,   155,   160,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      61,    62,    63,    64,   162,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   149,
      75,    76,    77,    78,    79,    80,     0,    20,    21,    22,
      23,     0,   158,     5,     0,     6,     7,     8,     9,   161,
       0,     0,   101,     0,     0,    24,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     5,     0,     6,     7,
       8,     9,     0,     0,     0,     0,   156,     0,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       9,     0,     0,    20,   102,    22,    23,    42,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     9,     0,     0,     0,    20,    21,    22,    23,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    20,     0,     0,    23,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
       0,    61,    62,    63,    64,     0,     0,    20,     0,     0,
      23,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   135,     0,
       0,     0,     0,     0,     0,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   136,     0,     0,     0,     0,     0,     0,    61,
      62,    63,    64,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   163,     0,     0,     0,
       0,     0,     0,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    95,    61,
      62,    63,    64,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   137,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   157,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    61,
      62,    63,    64,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    75,
      76,    77,    78,    79,    80,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,     0,
      70,    71,    72,     0,     0,    75,    76,    77,    78,    79,
      80,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,     0,     0,    71,    72,     0,
       0,    75,    76,    77,    78,    79,    80,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,    65,    66,    67,
       0,     0,     0,    71,    72,     0,     0,    75,    76,    77,
      78,    79,    80,    61,    62,    63,    64,     0,     0,     0,
       0,     0,     0,    65,    66,    67,     0,     0,     0,    71,
      72,     0,     0,    75,    76,    77,    78
  };

  const short int
  ScratchCodeParser::yycheck_[] =
  {
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     2,   135,   136,    16,    17,    18,    19,    18,
      19,    14,    15,     0,     8,    26,    27,    28,     8,     8,
     152,    39,    40,    41,    16,    17,    18,    19,     8,    53,
      15,   163,     4,     8,    26,    27,    28,    55,     9,    54,
      32,    33,   101,    61,    62,    53,    14,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    18,    19,     3,     9,     5,
       6,     7,     8,    26,    27,    28,    53,    53,   143,    14,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      16,    17,    18,    19,   160,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,   137,
      36,    37,    38,    39,    40,    41,    -1,    53,    54,    55,
      56,    -1,   150,     3,    -1,     5,     6,     7,     8,   157,
      -1,    -1,    12,    -1,    -1,   145,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     3,    -1,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    13,    -1,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
       8,    -1,    -1,    53,    54,    55,    56,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    53,    54,    55,    56,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    -1,    -1,    53,    -1,    -1,
      56,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
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
      49,    50,    51,    52,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    -1,    36,    37,    38,    39,    40,
      41,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    32,    33,    -1,
      -1,    36,    37,    38,    39,    40,    41,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    -1,    -1,    32,    33,    -1,    -1,    36,    37,    38,
      39,    40,    41,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,    32,
      33,    -1,    -1,    36,    37,    38,    39
  };

  const unsigned char
  ScratchCodeParser::yystos_[] =
  {
       0,    63,    65,     0,     0,     3,     5,     6,     7,     8,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      53,    54,    55,    56,    64,    68,    71,    72,    73,    74,
      75,    76,    80,    81,    82,    83,    84,    85,    88,     8,
       8,     8,    15,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,     8,    53,    70,    15,     4,
      15,    16,    17,    18,    19,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    82,    82,    82,    15,     9,    82,    86,     8,
      69,    12,    54,    64,    66,    67,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,     9,     9,    15,    87,     9,
      54,    77,    79,    14,    15,    65,    53,    67,    67,    82,
      14,    53,     9,    78,    53,    70,    13,    15,    82,    67,
      14,    82,    79,     9,    67
  };

  const unsigned char
  ScratchCodeParser::yyr1_[] =
  {
       0,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      71,    71,    72,    73,    74,    75,    76,    77,    77,    78,
      78,    79,    80,    80,    81,    82,    82,    82,    82,    82,
      83,    84,    85,    86,    86,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88
  };

  const unsigned char
  ScratchCodeParser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     2,     3,     1,     1,     4,     0,     3,     1,
       1,     3,     5,     9,     5,     2,     6,     0,     2,     0,
       3,     2,     2,     3,     2,     1,     1,     1,     3,     1,
       1,     1,     4,     0,     2,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
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
  "localVariableDefinition", "conditional", "conditionalIf", "forLoop",
  "whileLoop", "loopControlStatement", "functionDefinition",
  "functionDefinitionParameters", "functionDefinitionParametersMore",
  "functionDefinitionParameter", "returnStatement", "valueStandalone",
  "value", "lValue", "rValue", "functionCall", "functionCallParameters",
  "functionCallParametersMore", "operation", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  ScratchCodeParser::yyrline_[] =
  {
       0,   143,   143,   276,   277,   278,   279,   280,   281,   282,
     284,   288,   293,   300,   304,   311,   332,   343,   347,   353,
     364,   369,   377,   387,   398,   407,   417,   436,   440,   446,
     450,   457,   466,   472,   483,   489,   490,   491,   492,   496,
     533,   541,   546,   556,   560,   566,   570,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620
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
#line 2434 "gen/scratch-code.tab.cpp" // lalr1.cc:1167
#line 621 "src/scratch-code.ypp" // lalr1.cc:1168




#include "Main.hpp"

void yy::ScratchCodeParser::error(const yy::location& loc, const std::string& message)
{
	driver.handleError(loc, message);
}

