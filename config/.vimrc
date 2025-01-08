" Turn syntax highlighting on.
syntax on

" Add numbers to each line on the left-hand side.
set number

" Sets relative numbers.
set relativenumber

" Set colorscheme
colorscheme habamax

" Enable mouse support
set mouse=a

" Set the default indentation
set tabstop=4       " Number of spaces a <Tab> counts for
set shiftwidth=4    " Number of spaces to use for each step of (auto)indent
set noexpandtab       " Use spaces instead of tabs

" Enable line wrapping
set wrap

" add mapping for auto closing
imap "<tab> ""<Left>
imap '<tab> ''<Left>
imap (<tab> ()<Left>
imap [<tab> []<Left>
imap {<tab> {}<Left>
imap {<CR> {<CR>}<ESC>O
imap {;<CR> {<CR>};<ESC>O

" Enable file type detection
filetype plugin indent on

call plug#begin('~/.vim/plugged')

" Add plugins here
Plug 'morhetz/gruvbox'               " Gruvbox colorscheme
Plug 'tpope/vim-sensible'            " A sensible Vim configuration
Plug 'preservim/nerdtree'

nnoremap <Leader>n :NERDTreeToggle<CR>

call plug#end()
