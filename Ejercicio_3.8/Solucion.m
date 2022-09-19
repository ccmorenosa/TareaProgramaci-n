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
## @deftypefn {} {@var{retval} =} Solución (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Cindy Catalina Moreno <cata@Happy>
## Created: 2020-01-24

x=[-1:0.1:1];
y=F1(x);
x_plot=[-1:0.0001:1];
[poli]=polyfit(x,y,7);
p=polyval(poli,x_plot);
s=spline(x,y,x_plot);

gsf=scatter(x_plot,p,'r');
saveas(gsf,'Poli_1.pdf');

gss=scatter(x_plot,s,'g');
saveas(gss,'Spline_1.pdf');

for n=3:10
  x=[-1:2/(n-1):1];
  i=[0:n-1];
  y=x;
  for j=1:length(i)  
    y(j)=F2(i,j); 
  end
  x_plot=[-1:0.0001:1];
  [poli]=polyfit(x,y,7);
  p=polyval(poli,x_plot);
  s=spline(x,y,x_plot);

  gsf=scatter(x_plot,p,'r');
  name=sprintf('Poli_n_%d.pdf',n);
  saveas(gsf,name);
  
  name=sprintf('Spline_n_%d.pdf',n);
  gss=scatter(x_plot,s,'g');
  saveas(gss,name);
  
end