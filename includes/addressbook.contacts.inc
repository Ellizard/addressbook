<?php

function addressbook_contacts() {
  $output = '';
  $contacts = db_select('adressbook_table', 'n')
    ->fields('n', array('addressbook_id', 'addressbook_name', 'addressbook_lastname', 'addressbook_email', 'addressbook_photo', 'addressbook_phone'))
    ->execute()
    ->fetchAll();
  $header = array(
    t('id'),
    t('name'),
    t('lastname'),
    t('email'),
    t('photo'),
    t('phone'),
    t('options')
  );
  $rows = array();
  foreach ($contacts as $contact) {
    $photo = array(
      '#type'       => 'item',
      '#theme'      => 'image_style',
      '#style_name' => 'thumbnail',
      '#path'       => (file_load($contact->addressbook_photo)->uri),
    );
    $no_photo = t('No photo');
    $rows[] = array(
      $contact->addressbook_id,
      $contact->addressbook_name,
      $contact->addressbook_lastname,
      $contact->addressbook_email,
      ( $photo['#path'] !== NULL ) ? drupal_render($photo): $no_photo,
      $contact->addressbook_phone,
      $options = l(t('View'), 'admin/content/contacts/' . $contact ->addressbook_id . '/view').'<br>'.
                  l(t('Edit'), 'admin/content/contacts/' . $contact ->addressbook_id . '/edit').'<br>'.
                  l(t('Delete'), 'admin/content/contacts/' . $contact ->addressbook_id . '/delete'),
    );
  }
  $output .= theme('table', array('header' => $header, 'rows' => $rows));
  $output .= l(t('Add contact'), 'admin/content/contacts/add');
  return $output;
}