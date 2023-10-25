# LeetCode Problem 174 : Dungeon Game (Link : https://leetcode.com/problems/dungeon-game/)

def calculateMinimumHP(dungeon): # dungeon: List[List[int]]

    i,j,hp,m,n=0,0,0,len(dungeon),len(dungeon[0])
    steps=[]

    while i!=m-1 or j!=n-1:
        steps.append(dungeon[i][j])
        hp-=dungeon[i][j]
        if i==m-1: # If the Prince is on the last row of the dungeon
            j+=1
        elif j==n-1: # If the Prince is on the last column of the dungeon
            i+=1
        else:
            if dungeon[i+1][j]>dungeon[i][j+1]: # Comparing the possible steps to decide the next step
                i+=1
            else:
                j+=1

    hp=hp-dungeon[i][j]+1
    steps.append(dungeon[i][j])
    print('Steps involved :',steps[1:hp]) # Prints the steps taken in order

    return hp # Returns the minimum HP

def main():

    dungeon_test = [[7,-8,-9,1],[-10,0,1,-6],[-11,1,-3,-5],[-12,-1,-1,-4],[-13,-3,-2,-20]] # Test matrix for dungeon
    print('Minimum HP :',calculateMinimumHP(dungeon_test))

if __name__ == "__main__":
    main()