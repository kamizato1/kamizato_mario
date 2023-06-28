#include"dxlib.h"
#include"BoxCollider.h"

bool BoxCollider::HitBox(BoxCollider* bc)
{
    float sx1 = location.x - (size.x / 2);
    float sx2 = location.x + (size.x / 2);
    float sy1 = location.y - (size.y / 2);
    float sy2 = location.y + (size.y / 2);

    float dx1 = bc->location.x - (bc->size.x / 2);
    float dx2 = bc->location.x + (bc->size.x / 2);
    float dy1 = bc->location.y - (bc->size.y / 2);
    float dy2 = bc->location.y + (bc->size.y / 2);

    //‹éŒ`‚ªd‚È‚Á‚Ä‚¢‚ê‚Î“–‚½‚è
    if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2)return TRUE;

    return FALSE;
}

DATA BoxCollider::GetLocation()const
{
    return location;
}

DATA BoxCollider::GetSize()const
{
    return size;
}