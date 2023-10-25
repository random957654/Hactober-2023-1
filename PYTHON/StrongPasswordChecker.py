# LeetCode Problem 420 : Strong Password Checker (Link : https://leetcode.com/problems/strong-password-checker/)

def passwordchecker(pwd):

    for i in pwd: # Check for invalid characters
        if ((i not in list(map(chr, range(97,123)))) and
        (i not in list(map(chr, range(65,91)))) and
        (i not in list(map(chr, range(48,58)))) and i!='!' and i!='.'):
            print('Invalid Characters In Password')
            return 0
    if len(pwd)>50: # Check for invalid length
        print('Invalid Length Of Password')
        return 0
        
    changes=0
    req = [0,0,0] # req = [lower alphabets,upper alphabets,digits] (Counts of each type of required alphanumeric characters)
    ctrack = [0,0,0,0] # ctrack = [required types,repetitions,lack of characters,excess characters] (Counts of requirements in each check)

    for i in pwd: # Check for digits, lowercase and uppercase alphabets
        if i in list(map(chr, range(97,123))):
            req[0]+=1
        elif i in list(map(chr, range(65,91))):
            req[1]+=1
        elif i in list(map(chr, range(48,58))):
            req[2]+=1
    
    if req[1]==0:
        ctrack[0]+=1
    if req[0]==0:
        ctrack[0]+=1
    if req[2]==0:
        ctrack[0]+=1
    
    i=0
    while i<(len(pwd)-2): # Check for repetition of characters
        if pwd[i]==pwd[i+1] and pwd[i+1]==pwd[i+2]:
            ctrack[1]+=1
            i+=3
        else:
            i+=1
    
    if ctrack[1]>=ctrack[0]: # Check for possibility of repetitions being replaced by required types of characters
        changes=len(pwd)+ctrack[1]
    else:
        changes=len(pwd)+ctrack[0]
    
    if changes<6: # Check for limit of password length
        ctrack[2]=(6-changes)
    elif changes>20:
        ctrack[3]=(changes-20-ctrack[1])
    
    if ctrack[1]>=ctrack[0]+ctrack[3]: # Check for possibility of repetitive characters being deleted to satisfy length limit
        changes-=ctrack[3]
    elif ctrack[3]>0:
        changes-=(ctrack[1]-ctrack[0])

    changes+=(ctrack[3]+ctrack[2]-len(pwd)) # Final value for number of changes required
    print('Number of changes required =',changes)
    return changes
    
def main():

    pwd_test = 'db!....stttttt!.!5555' # Test password
    passwordchecker(pwd_test)

if __name__ == "__main__":
    main()