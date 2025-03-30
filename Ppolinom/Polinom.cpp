#include "Polinom.h"
ostream& operator<<(ostream& out, Polinom& p)
{
    if (p.IsEmpty()) return out;
    p.Reset();
    out << p.GetCurr();
    p.GoNext();
    for (; !p.IsEnd(); p.GoNext()) {
        out << (p.GetCurr().coeff > 1 ? "+" : "") << p.GetCurr();
    }
    return out;
}

istream& operator>>(istream& in, Polinom& p)
{
    double tmpCoeff;
    cin >> tmpCoeff;
    while (tmpCoeff != 0) {
        Monom* tmpMonom = new Monom();
        tmpMonom->coeff = tmpCoeff;
        try {
            cin >> tmpMonom->x >> tmpMonom->y >> tmpMonom->z;
        }
        catch (exception e) { throw e.what(); }
        p.Inslast(*tmpMonom);
        tmpCoeff = 0;
        cin >> tmpCoeff;
    }
    return in;
}

Polinom::Polinom(Monom* p, int sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        Inslast(p[i]);
    }
}

Polinom& Polinom::operator=(const Polinom& p) {
    if (this == &p) return *this;
    TList<Monom>::operator=(p);
    return *this;
}

bool Polinom::operator==(const Polinom& p) const {
    if (sz != p.sz)
        return false;
    if (sz == 0 && p.sz == 0)
        return true;
    Node<Monom>* node = pFirst;
    Node<Monom>* pnode = p.pFirst;
    while (node != nullptr)
    {
        if (node->value.coeff != pnode->value.coeff ||
            node->value.x != pnode->value.x ||
            node->value.y != pnode->value.y ||
            node->value.z != pnode->value.z)
            return false;
        node = node->pNext;
        pnode = pnode->pNext;
    }
    return true;
}

void Polinom::AddMonom(Monom m)
{
    if (IsEmpty())Inslast(m);
    else {
        if (pFirst->value < m) {
            InsFirst(m);
            return;
        }
        if (m < pLast->value) {
            Inslast(m);
            return;
        }
        for (Reset(); !IsEnd(); GoNext()) {
            if (GetCurr() < m) {
                Node<Monom>* add = new Node<Monom>(m);
                add->pNext = pCurr;
                pPrev->pNext = add;
                sz++;
                return;
            }
            if (GetCurr() == m) {
                double c = pCurr->value.coeff + m.coeff;
                if (c != 0) pCurr->value.coeff = c;
                else {
                    if (pCurr == pFirst) Pop();
                    else if (pCurr == pLast) {
                        pPrev->pNext = nullptr;
                        pLast = pPrev;
                        sz--;
                        delete pCurr;
                    }
                    else {
                        Node<Monom>* tmp = pCurr;
                        pPrev->pNext = pCurr->pNext;
                        sz--;
                        delete tmp;
                    }
                    return;
                }
            }
        }
    }
}
Polinom Polinom::operator+(Polinom& p)
{
    Polinom res(*this);
    for (res.Reset(), p.Reset(); (!res.IsEnd()) && (!p.IsEnd());) {
        Monom rcur = res.GetCurr(), pcur = p.GetCurr();
        if (rcur == pcur) {
            double c = rcur.coeff + pcur.coeff;
            if (c == 0) {
                res.DelCurr();
                p.GoNext();
            }
            else {
                res.GetCurr().coeff = c;
                res.GoNext();
                p.GoNext();
            }
        }
        else if (rcur < pcur) {
            res.InsCurr(pcur);
            p.GoNext();
        }
        else if (pcur < rcur) {
            res.GoNext();
        }
    }
    if (!p.IsEnd()) {
        for (; !p.IsEnd(); p.GoNext()) {
            res.Inslast(p.GetCurr());
        }
    }
    return res;
}
Polinom Polinom::operator-(Polinom& p)
{
    Polinom res, negative = p * (-1);
    res = *this + negative;
    return res;
}
Polinom Polinom::operator*(double coef)
{
    Polinom res(*this);
    if (coef == 0.0) res.Clear();
    else {
        for (res.Reset(); !res.IsEnd(); res.GoNext()) {
            res.GetCurr().coeff *= coef;
        }
    }
    return res;
}

Polinom Polinom::operator*(Polinom p)
{
    Polinom res, multer(*this);
    if (p.sz == 0) return res;
    for (p.Reset(); !(p.IsEnd()); (p.GoNext())) {
        Polinom tmp = (*this * p.GetCurr());
        res = (res + tmp);
    }
    return res;
}

Polinom Polinom::operator*(Monom m)
{
    Polinom res;
    if (m.coeff == 0.0) return res;
    for (Reset(); !IsEnd(); GoNext()) {
        Monom tmp;
        tmp.coeff = GetCurr().coeff * m.coeff;
        tmp.x = m.x + GetCurr().x;
        tmp.y = m.y + GetCurr().y;
        tmp.z = m.z + GetCurr().z;
        res.AddMonom(tmp);
    }
    return res;
}
