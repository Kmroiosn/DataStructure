# ADT String{

## Data Object:  
$$

D=\{a_i\, |\, a_i\in CharacterSet,i=1,2,3,...,n,n\ge 0\}  

$$
## Data Relationships:  
$$

R= \{<a_{i-1},a_i>|\, a_{i-1},a_i\in D,i=2,3,...,n\}  

$$
## Basic Operation:  
$$

strAssign(\&T,chars)  \\
    \qquad Initial\ Condition:\ chars\ is\ a\ string\ constant  \\
    \qquad Operation:\ Generate\ a\ string\ T\ with\ a\ value\ of\ chars  \\
strCopy(\&T,S)  \\
    \qquad Initial\ Condition:\ String\ S\ exists  \\
    \qquad Operation:\ Copy\ string\ T\ from\ string\ S  \\
strEmpty(S)  \\
    \qquad Initial\ Condition:\ String\ S\ exists  \\
    \qquad Operation:\ If\ string\ S\ is\ empty,\ return\ true;\ otherwise,\ return\ false  \\
strCompare(S,T)  \\
    \qquad Initial\ Condition:\ String\ S\ and\ T\ exists  \\
    \qquad Operation:\ If\ S>T,\ return\ value>0,\ if\ S=T,\ return\ value=0,\ if\ S<T,\ return\ value<0  \\
strLength(S)  \\
    \qquad Initial\ Condition:\ String\ S\ exists  \\
    \qquad Operation:\ Returns\ the\ number\ of\ elements\ in\ string\ S  \\
clearString(\&S)  \\
    \qquad Initial\ Condition:\ String\ S\ exists  \\
    \qquad Operation:\ Clear\ string\ S  \\
concat(\&T,S1,S2)  \\
    \qquad Initial\ Condition:\ String\ S1\ and\ S2\ exists  \\
    \qquad Operation:\ Use\ T\ to\ return\ the\ new\ string\ formed\ by\ concatenating\ S1\ and\ S2  \\
subString(\&Sub,S,pos,len)  \\
    \qquad Initial\ Condition:\ String\ S\ exists,\ 1\leq pos\leq strLength(S)\ and\ 0\leq len\leq strLength(S)-pos+1  \\
    \qquad Operation:\ Use\ Sub\ to\ return\ the\ substring\ of\ length\ len\ starting\ from\ the\ posth\ character\ of\ the\ string\ S  \\
index(S,T,pos)  \\
    \qquad Initial\ Condition:\ String\ S\ and\ T\ exists,\ T\ is\ not\ empty,\ 1\leq pos\leq strLength(S)   \\
    \qquad Operation:\ If\ there\ is\ a\ substring\ with\ the\ same\ value\ as\ string\ T\ in\ the\ main\ string\ S,\ then\ return\ the\ position\ where\ it\ appears\ for\ the\ first\ put outtime\ after\ the\ character\ pos\ in\ the\ main\ string\ S,\ otherwise\ the\ function\ value\ is\ 0  \\
replace(\&S,T,V)  \\
    \qquad Initial\ Condition:\ String\ S\ T\ V\ exists,\ string T\ is not empty  \\
    \qquad Operation:\ Replace\ all\ non-overlapping\ substrings\ equal\ to\ T\ that\ occur\ in\ the\ main\ string\ S\ with\ V  \\
strInsert(\&S,pos,T) \\
    \qquad Initial\ Condition:\ String\ S\ T\ exists,\ 1\leq pos\leq strLength(S)+1  \\
    \qquad Operation:\ Insert\ the\ string\ T\ before\ the\ pos\ character\ of\ the\ string\ S  \\
strDelete(\&S,pos,len) \\
    \qquad Initial\ Condition:\ String\ S\ exists,\ 1\leq pos\leq strLength(S)-len+1  \\
    \qquad Operation:\ Delete\ the\ pos\ substring\ of\ length\ len\ from\ the\ string\ S  \\
destroyString(\&S) \\
    \qquad Initial\ Condition:\ String\ S\ exists  \\
    \qquad Operation:\ Destroy\ string\ S  \\

$$

# }
