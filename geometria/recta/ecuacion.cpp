vector<Sca> ecuacion_recta (Punto p, Punto q) {
    Sca a = p.y - q.y;
    Sca b = q.x - p.x;
    Sca c = -a*p.x - b*p.y;
    Sca z = USO_FLOAT ? sqrtl(a*a + b*b) : __gcd(abs(a), __gcd(abs(b), abs(c)));
    a /= z, b /= z, c /= z;
    if (sca_le(a, 0) || (sca_eq(a, 0) && sca_le(b, 0))) a *= (-1), b *= (-1), c *= (-1);
    return {a, b, c};
}