## Copyright (C) 2020 Cindy Catalina Moreno
## 
## This program is free software; you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.

## -*- texinfo -*- 
## @deftypefn {} {@var{retval} =} F2 (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Cindy Catalina Moreno <cata@Happy>
## Created: 2020-01-24

function [retval] = F2 (i,j)
  retval= (-1)^(i(j)+1)*10^4;
  return;
endfunction
