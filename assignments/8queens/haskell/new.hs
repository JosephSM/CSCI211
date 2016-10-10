jfactorial 1 = 1 
jfactorial n = n * jfactorial n-1
jmap f [] = []
jmap f (x:xs) = f x : map f xs
jsum a b = a+b
map (sum 5) [1..10]


