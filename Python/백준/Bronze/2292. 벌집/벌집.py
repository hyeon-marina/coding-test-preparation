n = int(input())
honey = 1
layer = 1
while n > honey:
    honey += 6 * layer
    layer += 1
print(layer)
