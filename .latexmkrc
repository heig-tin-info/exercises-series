use strict;
use warnings;
use Cwd qw(abs_path);

my $root = abs_path('.');
my @tex_paths = ("$root/tex//", $root);
my $texinputs = join(':', @tex_paths);
$texinputs .= ':' . $ENV{TEXINPUTS} if defined $ENV{TEXINPUTS} && length $ENV{TEXINPUTS};
$texinputs .= ':';
$ENV{TEXINPUTS} = $texinputs;

my $luainputs = join(':', @tex_paths);
$luainputs .= ':' . $ENV{LUAINPUTS} if defined $ENV{LUAINPUTS} && length $ENV{LUAINPUTS};
$luainputs .= ':';
$ENV{LUAINPUTS} = $luainputs;

our $latex = 'lualatex %O %S';
our $pdflatex = 'lualatex %O %S';
our $pdf_mode = 1;
our $dvi_mode = 0;
our $postscript_mode = 0;
