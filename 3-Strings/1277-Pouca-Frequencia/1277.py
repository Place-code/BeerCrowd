for i in range (int(input())):
    input()
    students, reports = input().split(), input().split()
    rejected = []
    for student in students:
        nclass, attclass = 0, 0
        report = reports[0]
        for pres in report:
            if pres != 'M':
                nclass += 1
            if pres == 'P':
                attclass += 1
        reports.remove(report)
        if attclass/nclass < 0.75:
           rejected.append(student) 
    print (' '.join(rejected))