-- list of indexes
-- r, c
-- queen{0,0,0,0,0,0,0,0}
-- q[c]++
-- if checkQueen at q[c] -> c++
-- if !checkQueen at q[c] -> q[c]++,
-- if q[c] == 8 -> q[c] = 0, c--, q[c]++
-- if column == 8, printboard, 

main :: IO ()
main = print $ checker [0, 2, 0, 2, 0, 0, 0, 0] 3

type Queens = [Int]

incCol :: Queens -> Int -> Queens
incCol (q:qs) 0 = (q + 1) : qs
incCol (q:qs) n = q : incCol qs (n - 1)

checker :: Queens -> Int -> Bool
checker qs col = (not . or) $ (map diagFunc is) ++ isHorizontalCollision
    where
        row = qs !! col
        isHorizontalCollision = map horizFunc is
        is = [0..col - 1]
		    diagFunc i = col - i == abs (row - (qs !! i))
        horizFunc i = row == (qs !! i)

