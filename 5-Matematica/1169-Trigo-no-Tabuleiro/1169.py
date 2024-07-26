for _ in range(int(input())):
    dic = {"grao": 1, "kg" : 0}
    for i in range (int(input())):
        dic.update({"grao" : int(dic["grao"] * 2)})
    if dic["grao"] > 12000:
        dic.update({"kg": int(dic["grao"] // 12000)})
    print (dic["kg"], "kg")