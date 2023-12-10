import strutils
import algorithm
import math
proc si(): string = stdin.readLine
proc ni(): int = si().parseInt

let _=ni()
var s=si()
var cnt: array[10, int]
for x in s: cnt[ord(x)-ord('0')]+=1
let n=sorted(s,Descending).join("").parseInt
var ans=0
for i in 0..int(sqrt(float64(n))):
    let t=(i*i).intToStr
    var tmp: array[10, int]
    for x in t: tmp[ord(x)-ord('0')]+=1
    if s.len>t.len: tmp[0]+=s.len-t.len
    if cnt==tmp: ans+=1
echo ans