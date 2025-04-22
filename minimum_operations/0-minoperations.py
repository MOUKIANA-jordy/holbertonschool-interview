def minOperations(n):
    if n < 2:
        return 0
    operations = 0
    facteur = 2
    while n > 1:
        while n % facteur == 0:
            operations += facteur
            n //= facteur
        facteur += 1
    return operations

