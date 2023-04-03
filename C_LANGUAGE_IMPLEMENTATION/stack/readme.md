ADT Stack{  
Data Object:  
$$

D=\{a_i\, |\, a_i\in ElemType,i=1,2,3,...,n,n\ge 0\}  

$$
Data Relationships:  
$$

R= \{<a_{i-1},a_i>|\, a_{i-1},a_i\in D,i=2,3,...,n\}  

$$
Basic Operation:  
$$
\begin{align*}

&initStack(\&S)  \\
    &\qquad Operation: Construct an empty stack S  \\
&destroyStack(\&S)  \\
    &\qquad Initial Condition: Stack S exists  \\
    &\qquad Operation: Destroy stack S  \\
&clearStack(\&S)  \\
    &\qquad Initial Condition: Stack S exists  \\
    &\qquad Operation: Clear stack S  \\
&stackEmpty(S)  \\
    &\qquad Initial Condition: Stack S exists  \\
    &\qquad Operation: If stack S is empty, return true; otherwise, return false  \\
&stackLength(S)  \\
    &\qquad Initial Condition: Stack S exists  \\
    &\qquad Operation: Returns the number of elements in stack S  \\
&push(\&S,e)  \\
    &\qquad Initial Condition: Stack S exists  \\
    &\qquad Operation: Insert element e as the new top element of the stack  \\
&pop(\&S,\&e)  \\
    &\qquad Initial Condition: Stack S exists and is not empty  \\
    &\qquad Operation: Delete the top element of S and store the deleted value in e  \\
&getTop(S)  \\
    &\qquad Initial Condition: Stack S exists and is not empty  \\
    &\qquad Operation: Returns the top element of stack S  \\
&stackTraverse(S)  \\
    &\qquad Initial Condition: Stack S exists and is not empty  \\
    &\qquad Operation: Access each data element of S from the bottom of the stack to the top of the stack  \\

\end{align*}
$$
}
