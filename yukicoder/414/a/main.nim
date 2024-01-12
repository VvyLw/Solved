import sets
let nec=["watermelon","beachball","shrinebell"]
let s=[stdin.readLine,stdin.readLine].toHashSet
for el in nec:
    if not s.contains(el): echo el