def zap(a, b):
    return [(a[i], b[i]) for i in range(len(min(len(a), len(b))))]