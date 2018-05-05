; Script:       Russian Writer
; Description:  Turns an English keyboard into a Russian keyboard and back again
; Author:       The Geek on Skates
; License:      WTFL
; --------------------------------------------------------------------------------

; Auto-run section
#keyhistory off
#notrayicon
return

; Top row
+`::SendInput Ё
`::SendInput ё
+=::SendInput Ъ
=::SendInput ъ

; Second row
+Q::SendInput Я
q::SendInput я
+W::SendInput Ш
w::SendInput ш
+E::SendInput Е
e::SendInput е
+R::SendInput Р
r::SendInput р
+T::SendInput Т
t::SendInput т
+Y::SendInput Ы
y::SendInput ы
+U::SendInput У
u::SendInput у
+I::SendInput И
i::SendInput и
+O::SendInput О
o::SendInput о
+P::SendInput П
p::SendInput п
+[::SendInput Ю
[::SendInput ю
+]::SendInput Щ
]::SendInput щ
+\::SendInput Э
\::SendInput э

; Home row
+A::SendInput А
a::SendInput а
+S::SendInput С
s::SendInput с
+D::SendInput Д
d::SendInput д
+F::SendInput Ф
f::SendInput ф
+G::SendInput Г
g::SendInput г
+H::SendInput Ч
h::SendInput ч
+J::SendInput Й
j::SendInput й
+K::SendInput К
k::SendInput к
+L::SendInput Л
l::SendInput л
+`;::SendInput Ь
`;::SendInput ь
+'::SendInput Ж
'::SendInput ж

; Bottom row
+z::SendInput З
z::SendInput з
+X::SendInput Х
x::SendInput х
+C::SendInput Ц
c::SendInput ц
+V::SendInput В
v::SendInput в
+B::SendInput Б
b::SendInput б
+N::SendInput Н
n::SendInput н
+M::SendInput М
m::SendInput м

F5::Reload
^r::Suspend