\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{worksheet}[2025/02/14 Self-contained worksheet class for HEIG series]

\RequirePackage{expl3}
\RequirePackage{xparse}

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{exam}}
\ProcessOptions\relax

\LoadClass[french,a4paper,addpoints,11pt]{exam}

\RequirePackage[dvipsnames]{xcolor}
\RequirePackage{multicol}
\RequirePackage{graphicx}
\RequirePackage{xpatch}
\RequirePackage{realboxes}
\RequirePackage{textcomp}
\RequirePackage[ttdefault=true]{AnonymousPro}
\RequirePackage{parskip}
\RequirePackage{fontspec}
\RequirePackage{tikz}
\RequirePackage{booktabs}
\RequirePackage{hyperref}
\RequirePackage{xfrac}
\RequirePackage{tikzpagenodes}
\RequirePackage{inconsolata}
\RequirePackage{minted}
\RequirePackage[many,skins,breakable]{tcolorbox}
\tcbuselibrary{minted}
\RequirePackage{heiglogo}

\makeatletter
\providecommand\input@path{}
\g@addto@macro\input@path{{../../}{../}{./}}
\makeatother

% General layout/macro configuration (formerly hexercises-series.sty)
\setlength{\answerlinelength}{10cm}
\setlength{\answerskip}{3ex}
\setlength{\answerclearance}{1.1ex}
\CorrectChoiceEmphasis{}
\renewcommand{\thepartno}{\alph{partno}}
\renewcommand{\partlabel}{\thepartno.}
\renewcommand{\arraystretch}{1.75}
\pagestyle{headandfoot}
\AtBeginDocument{\thispagestyle{headandfoot}}

% Inline code helpers (former hexercises-common/hexercises)
\newcommand{\hexercisesInlineColor}{GitHubGray}
\newcommand{\sethexercisesinlinecolor}[1]{\renewcommand{\hexercisesInlineColor}{#1}}
\usemintedstyle{bw}
\tcbset{
  cinline/.style={
    on line,
    tcbox raise base,
    boxsep=1pt,
    left=3pt,
    right=3pt,
    top=1pt,
    bottom=1pt,
    colback=black!3,
    colframe=black!20,
    arc=2pt,
  },
}

\newcommand{\codebaseopts}{tabsize=4,breaklines,xleftmargin=0.4em,fontsize=\footnotesize,highlightcolor=gray!30,ignorelexererrors}
\tcbset{minted options={\codebaseopts}}

% \cinline[<lang>][<minted opts>] |code|
% \cinline[<lang>][<minted opts>]{code}
\ExplSyntaxOn
\NewDocumentCommand{\cinline}{ o o +v }{%
  \ifx\protect\@typeset@protect
    \IfNoValueTF{#1}{%
      \tcbox[cinline]{\texttt{\detokenize{#3}}}%
    }{%
      \IfBlankTF{#1}{%
        \tcbox[cinline]{\texttt{\detokenize{#3}}}%
      }{%
        \IfNoValueTF{#2}{%
          \tcbox[cinline]{\mintinline{#1}{#3}}%
        }{%
          \tcbox[cinline]{\mintinline[#2]{#1}{#3}}%
        }%
      }%
    }%
  \else
    \tcbox[cinline]{\texttt{\detokenize{#3}}}%
  \fi
}
\ExplSyntaxOff
\NewDocumentCommand{\canswer}{m}{\texttt{\detokenize{#1}}}

% Code environment using tcolorbox/minted combo
\newcommand{\codedefaultlang}{text}
\newcommand{\setdefaultcodelanguage}[1]{\renewcommand{\codedefaultlang}{#1}}
\newcommand{\setdefaultcodeoptions}[1]{%
  \if\relax\detokenize{#1}\relax
    \tcbset{minted options={\codebaseopts}}%
  \else
    \tcbset{minted options={\codebaseopts,#1}}%
  \fi
}
\NewTCBListing{code}{ O{\codedefaultlang} O{} O{} }{%
  listing engine     = minted,
  minted language    = #1,
  minted options     = {#2},
  enhanced,
  breakable,
  listing only,
  colback            = black!3,
  pad at break*      = 1mm,
  toptitle           = 0.15em,
  bottomtitle        = 0.1em,
  boxrule            = 0.15mm,
  arc                = 3pt,
  top                = 1mm,
  bottom             = 1mm,
  left               = 0pt,
  right              = 0pt,
  boxsep             = 0pt,
  colframe           = black!80,
  #3
}

% Exam presentation tweaks (from hexercises.sty)
\qformat{\textbf{Exercice \thequestion}\hfill}
\renewcommand{\questionshook}{\leftmargin=0pt%
  \labelwidth=-\labelsep}
\sethexercisesinlinecolor{GitHubGray}
\firstpagefooter{\revision}{}{Page \thepage\ sur \numpages}

\makeatletter
\DeclareRobustCommand*\school[1]{\gdef\@school{#1}}
\DeclareRobustCommand*\department[1]{\gdef\@department{#1}}
\DeclareRobustCommand*\seriesno[1]{\gdef\@seriesno{#1}}
\DeclareRobustCommand*\classroom[1]{\gdef\@classroom{#1}}
\InputIfFileExists{revision}{}{%
  \newcommand{\revision}{\texttt{dev}}%
  \newcommand{\revisiondate}{\today}%
}
\def\@maketitle{%
  \newpage
  \logo[height=1.5cm]
  \null
  \begin{center}%
    {\LARGE Série d'exercices \@seriesno \par}%
    \ifprintanswers Solution \fi

    {\LARGE \bfseries\@title \par}%
    \vskip 1.5em%
    {\@classroom}%
    \vskip 1.0em%
    {\revisiondate}
    \vskip 1.0em%
  \end{center}%
  \par
  \noindent\rule{\textwidth}{0.4pt}\vskip 1em}
\makeatother

\ExplSyntaxOn
\msg_new:nnn {worksheet}{seriesnumber-negative}
  { Series~number~must~be~a~non-negative~integer~(received~#1). }

\NewDocumentCommand{\course}{m}
  { \classroom{#1} }

\cs_new_protected:Npn \worksheet_set_seriesnumber:n #1
  {
    \int_set:Nn \l_tmpa_int {#1}
    \int_compare:nNnTF { \l_tmpa_int } < {0}
      { \msg_error:nnn {worksheet}{seriesnumber-negative}{#1} }
      {
        \tl_set:Nx \l_tmpa_tl { \int_to_Hex:n { \l_tmpa_int } }
        \int_compare:nNnT { \tl_count:N \l_tmpa_tl } < {2}
          { \tl_set:Nx \l_tmpa_tl { 0\l_tmpa_tl } }
        \seriesno{\texttt{0x\l_tmpa_tl}}
      }
  }

\NewDocumentCommand{\seriesnumber}{m}
  { \worksheet_set_seriesnumber:n {#1} }

\NewDocumentCommand{\serieslabel}{m}
  { \seriesno{\texttt{#1}} }
\ExplSyntaxOff
