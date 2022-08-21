def tandemBicycle(redShirtSpeeds, blueShirtSpeeds, fastest):
    # O(nlogn) Time
    # O(1) Spcace

    redShirtSpeeds.sort()
    blueShirtSpeeds.sort()
    total_speed = 0

    if(fastest):
        redShirtSpeeds.sort(reverse = True)
    
    for i in range(len(redShirtSpeeds)):
        total_speed += max(redShirtSpeeds[i], blueShirtSpeeds[i])
    
    return total_speed


red = [1, 4, 7]
blue = [3, 5, 3] 

print("result is", tandemBicycle(red, blue, True))