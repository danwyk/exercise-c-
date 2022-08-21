def classPhotos(redShirtHeights, blueShirtHeights):
    # O(nlogn) Time
    # O(1) Space
    redShirtHeights.sort()
    blueShirtHeights.sort()
    isRedBack = False

    if(redShirtHeights[-1] == blueShirtHeights[-1]):
      return False
    elif(redShirtHeights[-1] > blueShirtHeights[-1]):
      isRedBack = True
    
    for i in range(len(redShirtHeights)):
      if(isRedBack and redShirtHeights[i] <= blueShirtHeights[i]):
        return False
      elif(not isRedBack and blueShirtHeights[i] <= redShirtHeights[i]):
        return False

    return True


redRow = [5, 8, 1, 3, 4]
blueRow = [6, 9, 2, 4, 5]

print(classPhotos(redRow, blueRow))