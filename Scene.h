#pragma once

// ȭ���� �׸��� ���� �� ȭ�鿡 �ִ� ��� ó��(��ü�� ����ִ� ��) ������ �մϴ�.
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

};