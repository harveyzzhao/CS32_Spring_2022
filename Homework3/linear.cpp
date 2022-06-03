#include <string>
#include <iostream>
#include <cassert>
using namespace std;

// Return false if the somePredicate function returns true for at
// least one of the array elements; return true otherwise.
bool somePredicate(string wrd)
{
    return (wrd == "1");
}

bool allFalse(const string a[], int n)
{
    if (n <= 0) return true;
    if (somePredicate(a[0]) == true) return false;
    return allFalse(a + 1, n - 1);
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{
    if (n <= 0) return 0;
    return (somePredicate(a[0]) == false) ? 1 + countFalse(a + 1, n - 1) : countFalse(a + 1, n - 1);
}

//Return the subscript of the first element in the array for which
//the somePredicate function returns false.  If there is no such
//element, return -1.
int firstFalse(const string a[], int n)
{
    if (n <= 0) return -1;
    if (somePredicate(a[0]) == false)   return 0;
    int nextVal = firstFalse(a+1, n-1);
    return (nextVal != -1) ? 1 + nextVal : -1;
}

// Return the subscript of the least string in the array (i.e.,
// return the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the function is told that no strings are to
// be considered in the array, return -1.
int positionOfLeast(const string a[], int n)
{
    if (n <= 0) return -1;
    if (n == 1) return 0;
    int posOfLeast = positionOfLeast(a+1, n-1) + 1;
    return (a[0] <= a[posOfLeast]) ? 0 : posOfLeast;
}

//tester for positionOfLeast - implementation in standard logic
int testLeast(const string a[], int n)
{
    int index = -1;
    string least = "a";
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] <= least)
        {
            least = a[i];
            index = i;
        }
    }
    return index;
}

bool has(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0)    return true;
    if (n1 <= 0)    return false;
    if (a1[0] == a2[0]) return has(a1+1, n1-1, a2+1, n2-1);
    return has(a1+1, n1-1, a2, n2);
}

// Exchange two strings
void exchange(string& x, string& y)
{
  string t = x;
  x = y;
  y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is < splitter come before all the other elements,
// and all the elements whose value is > splitter come after all
// the other elements.
// Upon return, firstNotLess is set to the
// index of the first element in the rearranged array that is
// >= splitter, or n if there is no such element, and firstGreater is
// set to the index of the first element that is > splitter, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotLess, a[i] < splitter
//   * for firstNotLess <= i < firstGreater, a[i] == splitter
//   * for firstGreater <= i < n, a[i] > splitter
// All the elements < splitter end up in no particular order.
// All the elements > splitter end up in no particular order.
void split(string a[], int n, string splitter,
                                  int& firstNotLess, int& firstGreater)
{
  if (n < 0)
      n = 0;

    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
    //  Every element earlier than position firstNotLess is < splitter
    //  Every element from position firstNotLess to firstUnknown-1 is
    //    == splitter
    //  Every element from firstUnknown to firstGreater-1 is not known yet
    //  Every element at position firstGreater or later is > splitter

  firstNotLess = 0;
  firstGreater = n;
  int firstUnknown = 0;
  while (firstUnknown < firstGreater)
  {
      if (a[firstUnknown] > splitter)
      {
          firstGreater--;
          exchange(a[firstUnknown], a[firstGreater]);
      }
      else
      {
          if (a[firstUnknown] < splitter)
          {
              exchange(a[firstNotLess], a[firstUnknown]);
              firstNotLess++;
          }
          firstUnknown++;
      }
  }
}

// Rearrange the elements of the array so that
// a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
// If n <= 1, do nothing.
void order(string a[], int n)
{
  if (n <= 1)   return;
  int fnl = 0, fg = 0;
  split(a, n, a[0], fnl, fg);
  order(a, fnl);  //splits the array into two halves
  order(a+fg, n-fg);  //since we don't know what the value of fg is compared to the values that are bigger than the splitter.
}

void display(string a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    cout << "=================================" << endl;
}

int numberOfTimesHas(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0)  return 1;
    if (n1 <= 0)  return 0;
    if (a1[0] == a2[0])
    {
        int var = numberOfTimesHas(a1+1, n1-1, a2+1, n2-1);
        if (var != 0)
            return var + numberOfTimesHas(a1+1, n1-1, a2, n2);
    }
    return numberOfTimesHas(a1+1, n1-1, a2, n2);
}

int main()
{
    string alpha[] = {"1", "ab"};
    assert(allFalse(alpha, 2) == false);
    assert(countFalse(alpha, 2) == 1);
    assert(firstFalse(alpha, 2) == 1);
    assert(positionOfLeast(alpha, 2) == 0);

    string beta[] = {"a", "", "ra", "d", "0", "f"};
    assert(allFalse(beta, 6) == true);
    assert(countFalse(beta, 6) == 6);
    assert(firstFalse(beta, 6) == 0);
    assert(positionOfLeast(beta, 6) == 1);

    string gamma[] = {"1", "1", "1", "1", "1", "1"};
    assert(allFalse(gamma, 6) == false);
    assert(countFalse(gamma, 6) == 0);
    assert(firstFalse(gamma, 6) == -1);
    assert(positionOfLeast(gamma, 6) == 0);

    string delta[] {"1", "1", "2", "1", "0", "3"};
    assert(allFalse(delta, 6) == false);
    assert(countFalse(delta, 6) == 3);
    assert(firstFalse(delta, 6) == 2);
    assert(positionOfLeast(delta, 6) == 4);

    string epsilon[] {"b", "a", "b", "b"};
    assert(allFalse(epsilon, 4) == true);
    assert(countFalse(epsilon, 4) == 4);
    assert(firstFalse(epsilon, 4) == 0);
    assert(testLeast(epsilon, 4) == 1);
    assert(positionOfLeast(epsilon, 4) == 1);

    string zeta[] {"b", "a", "c", "b"};
    assert(allFalse(epsilon, 4) == true);
    assert(countFalse(epsilon, 4) == 4);
    assert(firstFalse(epsilon, 4) == 0);
    assert(testLeast(epsilon, 4) == 1);
    assert(positionOfLeast(epsilon, 4) == 1);
    assert(numberOfTimesHas(epsilon, 4, zeta, 4) == 0);

    string eta[] = {};
    assert(allFalse(eta, 0) == true);
    assert(countFalse(eta, 0) == 0);
    assert(firstFalse(eta, 0) == -1);
    assert(testLeast(eta, 0) == -1);
    assert(positionOfLeast(eta, 0) == -1);
    assert(has(eta, 0, alpha, 2) == false);
    assert(has(eta, 0, beta, 6) == false);
    assert(has(eta, 0, gamma, 6) == false);
    assert(has(eta, 0, delta, 6) == false);
    assert(has(eta, 0, epsilon, 4) == false);
    assert(has(eta, 0, zeta, 4) == false);
    assert(has(eta, 0, eta, 0) == true);
    assert(has(alpha, 2, eta, 0) == true);
    assert(has(beta, 6, eta, 0) == true);
    assert(has(gamma, 6, eta, 0) == true);
    assert(has(delta, 6, eta, 0) == true);
    assert(has(epsilon, 4, eta, 0) == true);
    assert(has(zeta, 4, eta, 0) == true);
    assert(numberOfTimesHas(eta, 0, eta, 0) == 1);

    string theta[] = {"1", "2", "a", "b", "3", "0"};
    assert(allFalse(theta, 6) == false);
    assert(countFalse(theta, 6) == 5);
    assert(firstFalse(theta, 6) == 1);
    assert(positionOfLeast(theta, 6) == 5);

    string iota[] = {"1"};
    assert(allFalse(iota, 1) == false);
    assert(countFalse(iota, 1) == 0);
    assert(firstFalse(iota, 1) == -1);
    assert(positionOfLeast(iota, 1) == 0);
    assert(has(theta, 6, iota, 1) == true);
    assert(has(iota, 1, theta, 6) == false);
    assert(has(iota, 1, iota, 1) == true);
    assert(has(zeta, 4, iota, 1) == false);
    assert(has(delta, 6, iota, 1) == true);
    assert(has(gamma, 6, iota, 1) == true);
    assert(has(alpha, 2, iota, 1) == true);
    assert(numberOfTimesHas(theta, 6, iota, 1) == 1);
    assert(numberOfTimesHas(alpha, 2, iota, 1) == 1);
    assert(numberOfTimesHas(beta, 6, iota, 1) == 0);
    assert(numberOfTimesHas(gamma, 6, iota, 1) == 6);
    assert(numberOfTimesHas(delta, 6, iota, 1) == 3);
    assert(numberOfTimesHas(epsilon, 4, iota, 1) == 0);
    assert(numberOfTimesHas(zeta, 4, iota, 1) == 0);
    assert(numberOfTimesHas(eta, 0, iota, 1) == 0);
    assert(numberOfTimesHas(iota, 1, eta, 0) == 1);
    assert(numberOfTimesHas(iota, 1, iota, 1) == 1);

    string kappa[] = {"1", "1"};
    assert(allFalse(kappa, 2) == false);
    assert(countFalse(kappa, 2) == 0);
    assert(firstFalse(kappa, 2) == -1);
    assert(positionOfLeast(kappa, 2) == 0);
    assert(has(kappa, 2, iota, 1) == true);
    assert(has(theta, 6, kappa, 2) == false);
    assert(has(kappa, 2, theta, 6) == false);
    assert(has(kappa, 2, kappa, 2) == true);
    assert(has(zeta, 4, kappa, 2) == false);
    assert(has(delta, 6, kappa, 2) == true);
    assert(has(gamma, 6, kappa, 2) == true);

    string lambda[] = {"a", "a", "b", "b", "c"};
    string mu[] = {"a", "b", "c"};
    assert(has(lambda, 5, mu, 3) == true);
    assert(numberOfTimesHas(lambda, 5, mu, 3) == 4);

    string nu[] = {"a", "b", "b", "c"};
    string xi[] = {"c", "b", "a"};
    assert(has(nu, 4, xi, 3) == false);
    assert(numberOfTimesHas(nu, 4, xi, 3) == 0);

    string omicron[] = {"merida", "tiana", "raya", "belle", "tiana", "raya", "moana"};
    string pi[] = {"tiana", "belle", "moana"};
    string rho[] = {"tiana", "raya", "raya"};
    string sigma[] = {"tiana", "moana", "belle"};
    string tau[] = {"merida", "belle", "belle"};
    assert(has(omicron, 7, pi, 3) == true);
    assert(has(omicron, 7, rho, 3) == true);
    assert(has(omicron, 7, sigma, 3) == false);
    assert(has(omicron, 7, tau, 3) == false);

    string upsilon[] = {"0", "0", "1", "1"};
    string phi[] = {"0", "1"};
    assert(numberOfTimesHas(upsilon, 4, phi, 2) == 4);

    string chi[] = {"merida", "belle", "raya"};
    string psi[] = {"merida", "raya", "moana"};
    string omega[] = {"belle", "merida", "raya"};
    string alphaAlpha[] = {"tiana", "raya", "moana"};
    assert(numberOfTimesHas(omicron, 7, chi, 3) == 1);
    assert(numberOfTimesHas(omicron, 7, psi, 3) == 2);
    assert(numberOfTimesHas(omicron, 7, omega, 3) == 0);
    assert(numberOfTimesHas(omicron, 7, alphaAlpha, 3) == 3);

    string alphaBeta[] = {"a", "b", "a", "a"};
    string alphaGamma[] = {"a", "b"};
    assert(numberOfTimesHas(alphaBeta, 4, alphaGamma, 2) == 1);

    string alphaDelta[] = {"a", "b", "a", "a", "b"};
    assert(numberOfTimesHas(alphaDelta, 5, alphaGamma, 2) == 4);

    order(alpha, 2);
        display(alpha, 2);
    order(beta, 6);
        display(beta, 6);
    order(gamma, 6);
        display(gamma, 6);
    order(delta, 6);
        display(delta, 6);
    order(epsilon, 4);
        display(epsilon, 4);
    order(zeta, 4);
        display(zeta, 4);
    order(eta, 0);
        display(eta, 0);
    order(theta, 6);
        display(theta, 6);
    order(iota, 1);
        display(iota, 1);
    order(kappa, 2);
        display(kappa, 2);
    order(lambda, 5);
        display(lambda, 5);
    order(mu, 3);
        display(mu, 3);
    order(nu, 4);
        display(nu, 4);
    order(xi, 3);
        display(xi, 3);
    order(omicron, 7);
        display(omicron, 7);
    order(pi, 3);
        display(pi, 3);
    order(rho, 3);
        display(rho, 3);
    order(sigma, 3);
        display(sigma, 3);
    order(tau, 3);
        display(tau, 3);
    order(upsilon, 4);
        display(upsilon, 4);
    order(phi, 2);
        display(phi, 2);
    order(chi, 3);
        display(chi, 3);
    order(psi, 3);
        display(psi, 3);
    order(omega, 3);
        display(omega, 3);
    order(alphaAlpha, 3);
        display(alphaAlpha, 3);
    order(alphaBeta, 4);
        display(alphaBeta, 4);
    order(alphaGamma, 2);
        display(alphaGamma, 2);
    order(alphaDelta, 5);
        display(alphaDelta, 5);

    cout << "passed all tests." << endl;
}
