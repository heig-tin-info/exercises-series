\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{worksheet}[2025/02/14 Simplified worksheet class for HEIG series]

\RequirePackage{expl3}
\RequirePackage{xparse}

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{exam}}
\ProcessOptions\relax

\LoadClass[french,a4paper,addpoints,11pt]{exam}

\RequirePackage{hexercises-series}

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
