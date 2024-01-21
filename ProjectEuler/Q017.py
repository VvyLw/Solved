import inflect
eng = inflect.engine()
s=0
for i in range(1,1001):
    t=eng.number_to_words(i)
    t=t.replace(' ','')
    t=t.replace('-','')
    s+=len(t)
print(s)