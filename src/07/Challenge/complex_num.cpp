#include "complex_num.h"

complex_num::complex_num(double r, double i) :
m_r(r),
m_i(i)
{
    // Write your code here
}

complex_num complex_num::operator +(const complex_num& w){
    complex_num z(m_r + w.m_r, m_i + w.m_i);
    // Write your code here
    return z;
}

complex_num complex_num::operator -(const complex_num& w){
    complex_num z(m_r - w.m_r, m_i - w.m_i);
    // Write your code here
    return z;
}

// complex_num complex_num::operator *(complex_num w){
//     complex_num z;
//     // Write your code here
//     return z;
// }

// complex_num complex_num::operator /(complex_num w){
//     complex_num z;
//     // Write your code here
//     return z;
// }

void complex_num::print(std::ostream &os){
    // Write your code here
    os << '(' << m_r << (m_i < 0 ? " - " : " + ") << std::abs(m_i) << 'i)' << std::endl;
}