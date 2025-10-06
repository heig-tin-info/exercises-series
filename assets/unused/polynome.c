long factoriel(long n)
{
  return n == 0 ? 1 : n * factoriel(n-1);
}

double power(double x, int n)
{
  double result = 1.0;
  for (int i = 0; i < n; i++)
    result *= x;
  return result;
}

double compute_polynom(double x)
{
  double result = 0;
  for (int i = 0; i <= 5; i++)
    result += i*power(x, i)/factoriel(i);
  return result;
}
