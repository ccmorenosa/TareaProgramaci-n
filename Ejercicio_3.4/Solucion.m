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
## @deftypefn {} {@var{retval} =} Solucion (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Cindy Catalina Moreno <cata@Happy>
## Created: 2020-01-24

x=[0,13,36,62,86,98,108,156];
y=[4.5,5.0,6.0,6.5,7.0,7.5,8.0,8.0];

[coef]=polyfit(x,y,7);

P_Nov_2020=polyval(coef,180)